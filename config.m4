PHP_ARG_ENABLE(hext, whether to enable hext support,
Make sure that the comment is aligned:
[  --enable-hext           Enable hext support])

if test "$PHP_HEXT" != "no"; then
  PHP_NEW_EXTENSION(hext, hext.c, $ext_shared)
fi
