//! WinScore as the app that opens `.mus` files. The bundle declares the
//! type and claims it as its owner (tauri.conf.json's `fileAssociations`:
//! `rank` Owner, an exported type), which Launch Services follows where no
//! other choice was made; on macOS the app also asks Launch Services to make
//! it the default handler for the type, once at its first start and whenever
//! the menu command asks.

/// The type the bundle exports for `.mus` files (tauri.conf.json).
pub const EXPORTED_TYPE: &str = "io.github.pfefferniels.winscore.mus";

#[cfg(target_os = "macos")]
mod launch_services {
    use std::ffi::c_void;
    use std::ptr;

    type CFStringRef = *const c_void;

    const UTF8: u32 = 0x0800_0100;
    const ALL_ROLES: u32 = 0xFFFF_FFFF;

    #[link(name = "CoreFoundation", kind = "framework")]
    extern "C" {
        fn CFStringCreateWithBytes(allocator: *const c_void, bytes: *const u8, length: isize, encoding: u32, external: u8) -> CFStringRef;
        fn CFRelease(object: *const c_void);
    }

    #[link(name = "CoreServices", kind = "framework")]
    extern "C" {
        static kUTTagClassFilenameExtension: CFStringRef;
        fn UTTypeCreatePreferredIdentifierForTag(tag_class: CFStringRef, tag: CFStringRef, conforming_to: CFStringRef) -> CFStringRef;
        fn LSSetDefaultRoleHandlerForContentType(content_type: CFStringRef, role: u32, handler: CFStringRef) -> i32;
    }

    /// A Core Foundation string, released when dropped.
    struct CfString(CFStringRef);

    impl CfString {
        fn new(text: &str) -> Self {
            // SAFETY: the bytes are valid UTF-8 for the given length; a null allocator is the default one.
            Self(unsafe { CFStringCreateWithBytes(ptr::null(), text.as_ptr(), text.len() as isize, UTF8, 0) })
        }
    }

    impl Drop for CfString {
        fn drop(&mut self) {
            if !self.0.is_null() {
                // SAFETY: the string was created by a Create function and is released once.
                unsafe { CFRelease(self.0) }
            }
        }
    }

    /// Makes the app `bundle_id` the handler of every role for files with
    /// extension `extension` (the type the system takes them for) and for
    /// `exported`, the app's own type for them.
    pub fn set_default(bundle_id: &str, extension: &str, exported: &str) -> Result<(), String> {
        let handler = CfString::new(bundle_id);
        let tag = CfString::new(extension);
        // SAFETY: the arguments are valid strings or null; the result is owned and released.
        let resolved = CfString(unsafe { UTTypeCreatePreferredIdentifierForTag(kUTTagClassFilenameExtension, tag.0, ptr::null()) });
        let own = CfString::new(exported);
        let mut statuses = Vec::new();
        for content_type in [&resolved, &own] {
            if !content_type.0.is_null() {
                // SAFETY: both strings are valid for the call.
                statuses.push(unsafe { LSSetDefaultRoleHandlerForContentType(content_type.0, ALL_ROLES, handler.0) });
            }
        }
        // Either type will do: the system takes .mus files for one of them.
        if statuses.contains(&0) {
            Ok(())
        } else {
            Err(format!("Launch Services refused (status {statuses:?})"))
        }
    }
}

/// Makes the app with bundle identifier `bundle_id` the one that opens `.mus` files.
pub fn set_default(bundle_id: &str) -> Result<(), String> {
    #[cfg(target_os = "macos")]
    {
        launch_services::set_default(bundle_id, "mus", EXPORTED_TYPE)
    }
    #[cfg(not(target_os = "macos"))]
    {
        let _ = bundle_id;
        Err("only on macOS: elsewhere the system's settings choose the app for .mus files".into())
    }
}
