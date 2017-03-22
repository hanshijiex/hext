dnl $Id$
dnl config.m4 for extension hext

dnl Comments in this file start with the string 'dnl'.
dnl Remove where necessary. This file will not work
dnl without editing.

dnl If your extension references something external, use with:

dnl PHP_ARG_WITH(hext, for hext support,
dnl Make sure that the comment is aligned:
dnl [  --with-hext             Include hext support])

dnl Otherwise use enable:

dnl PHP_ARG_ENABLE(hext, whether to enable hext support,
dnl Make sure that the comment is aligned:
dnl [  --enable-hext           Enable hext support])

if test "$PHP_HEXT" != "no"; then
  dnl Write more examples of tests here...

  dnl # --with-hext -> check with-path
  dnl SEARCH_PATH="/usr/local /usr"     # you might want to change this
  dnl SEARCH_FOR="/include/hext.h"  # you most likely want to change this
  dnl if test -r $PHP_HEXT/$SEARCH_FOR; then # path given as parameter
  dnl   HEXT_DIR=$PHP_HEXT
  dnl else # search default path list
  dnl   AC_MSG_CHECKING([for hext files in default path])
  dnl   for i in $SEARCH_PATH ; do
  dnl     if test -r $i/$SEARCH_FOR; then
  dnl       HEXT_DIR=$i
  dnl       AC_MSG_RESULT(found in $i)
  dnl     fi
  dnl   done
  dnl fi
  dnl
  dnl if test -z "$HEXT_DIR"; then
  dnl   AC_MSG_RESULT([not found])
  dnl   AC_MSG_ERROR([Please reinstall the hext distribution])
  dnl fi

  dnl # --with-hext -> add include path
  dnl PHP_ADD_INCLUDE($HEXT_DIR/include)

  dnl # --with-hext -> check for lib and symbol presence
  dnl LIBNAME=hext # you may want to change this
  dnl LIBSYMBOL=hext # you most likely want to change this 

  dnl PHP_CHECK_LIBRARY($LIBNAME,$LIBSYMBOL,
  dnl [
  dnl   PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $HEXT_DIR/$PHP_LIBDIR, HEXT_SHARED_LIBADD)
  dnl   AC_DEFINE(HAVE_HEXTLIB,1,[ ])
  dnl ],[
  dnl   AC_MSG_ERROR([wrong hext lib version or lib not found])
  dnl ],[
  dnl   -L$HEXT_DIR/$PHP_LIBDIR -lm
  dnl ])
  dnl
  dnl PHP_SUBST(HEXT_SHARED_LIBADD)

  PHP_NEW_EXTENSION(hext, hext.c, $ext_shared)
fi
