/*
  +----------------------------------------------------------------------+
  | PHP Version 5                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2016 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author:                                                              |
  +----------------------------------------------------------------------+
*/

/* $Id$ */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "php_hext.h"

/* If you declare any globals in php_hext.h uncomment this:
ZEND_DECLARE_MODULE_GLOBALS(hext)
*/

/* True global resources - no need for thread safety here */
static int le_hext;

PHP_FUNCTION(confirm_hext_compiled)
{
	char *arg = NULL;
	int arg_len, len;
	char *strg;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &arg, &arg_len) == FAILURE) {
		return;
	}

	len = spprintf(&strg, 0, "Congratulations! You have successfully modified ext/%.78s/config.m4. Module %.78s is now compiled into PHP.", "hext", arg);
	RETURN_STRINGL(strg, len, 0);
}

PHP_FUNCTION(hello)
{
	php_printf("Hello World!\n");
}


PHP_MINIT_FUNCTION(hext)
{
	/* If you have INI entries, uncomment these lines 
	REGISTER_INI_ENTRIES();
	*/
	return SUCCESS;
}

PHP_MSHUTDOWN_FUNCTION(hext)
{
	/* uncomment this line if you have INI entries
	UNREGISTER_INI_ENTRIES();
	*/
	return SUCCESS;
}

PHP_RINIT_FUNCTION(hext)
{
	return SUCCESS;
}

PHP_RSHUTDOWN_FUNCTION(hext)
{
	return SUCCESS;
}

PHP_MINFO_FUNCTION(hext)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "hext support", "enabled");
	php_info_print_table_end();

	/* Remove comments if you have entries in php.ini
	DISPLAY_INI_ENTRIES();
	*/
}

const zend_function_entry hext_functions[] = {
	PHP_FE(confirm_hext_compiled,	NULL)		/* For testing, remove later. */
	PHP_FE(hello,	NULL)		/* For testing, remove later. */
	PHP_FE_END	/* Must be the last line in hext_functions[] */
};

zend_module_entry hext_module_entry = {
	STANDARD_MODULE_HEADER,
	"hext",
	hext_functions,
	PHP_MINIT(hext),
	PHP_MSHUTDOWN(hext),
	PHP_RINIT(hext),		/* Replace with NULL if there's nothing to do at request start */
	PHP_RSHUTDOWN(hext),	/* Replace with NULL if there's nothing to do at request end */
	PHP_MINFO(hext),
	PHP_HEXT_VERSION,
	STANDARD_MODULE_PROPERTIES
};

#ifdef COMPILE_DL_HEXT
ZEND_GET_MODULE(hext)
#endif

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
