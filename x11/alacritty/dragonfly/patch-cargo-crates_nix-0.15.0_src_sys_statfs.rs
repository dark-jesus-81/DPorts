--- cargo-crates/nix-0.15.0/src/sys/statfs.rs.orig	2019-06-23 13:37:36 UTC
+++ cargo-crates/nix-0.15.0/src/sys/statfs.rs
@@ -20,6 +20,9 @@ pub struct Statfs(libc::statfs);
 #[cfg(target_os = "freebsd")]
 #[derive(Eq, Copy, Clone, PartialEq, Debug)]
 pub struct FsType(u32);
+#[cfg(target_os = "dragonfly")]
+#[derive(Eq, Copy, Clone, PartialEq, Debug)]
+pub struct FsType(i32);
 #[cfg(target_os = "android")]
 #[derive(Eq, Copy, Clone, PartialEq, Debug)]
 pub struct FsType(libc::c_ulong);
