
$FreeBSD: head/net/erlang_xmlrpc/files/patch-src_xmlrpc__decode.erl 340725 2014-01-22 17:40:44Z mat $

--- src/xmlrpc_decode.erl.orig	Tue Oct 12 21:02:55 2004
+++ src/xmlrpc_decode.erl	Tue Oct 12 21:03:43 2004
@@ -28,7 +28,7 @@
 -author('jocke@gleipnir.com').
 -export([payload/1]).
 
--include("xmerl.hrl").
+-include_lib("xmerl/include/xmerl.hrl").
 
 payload(Payload) ->
     case xmerl_scan:string(Payload) of
