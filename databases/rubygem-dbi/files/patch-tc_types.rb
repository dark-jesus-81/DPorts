--- test/dbi/tc_types.rb.orig	2014-10-17 15:44:22.000000000 +0200
+++ test/dbi/tc_types.rb	2014-10-17 15:48:58.000000000 +0200
@@ -114,11 +114,7 @@
         d = Date.today
         assert_equal(DateTime.parse(d.to_s).to_s, klass.parse(d).to_s)
 
-        md = "10-11"
-
-        if RUBY_VERSION =~ /^1\.9/
             md = "11-10"
-        end
 
         # be sure we're actually getting the right data back
         assert_equal(
