--- ./DiffWindow.cxx.orig	2006-11-13 19:54:02.000000000 +0100
+++ ./DiffWindow.cxx	2011-09-08 10:20:08.000000000 +0200
@@ -1126,11 +1126,11 @@
 DiffWindow::save_prefs()
 {
   // Save the window prefs for the next run...
-  prefs_.set("color", color());
-  prefs_.set("selection_color", selection_color());
+  prefs_.set("color", static_cast<int>(color()));
+  prefs_.set("selection_color", static_cast<int>(selection_color()));
   prefs_.set("showlinenum", showlinenum());
   prefs_.set("tabwidth", tabwidth());
-  prefs_.set("textcolor", textcolor());
+  prefs_.set("textcolor", static_cast<int>(textcolor()));
   prefs_.set("textsize", textsize());
   prefs_.set("ignoreblanks", ignoreblanks());
 }
