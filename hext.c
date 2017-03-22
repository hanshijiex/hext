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

/* {{{ PHP_INI
 */
/* Remove comments and fill if you need to have entries in php.ini
PHP_INI_BEGIN()
    STD_PHP_INI_ENTRY("hext.global_value",      "42", PHP_INI_ALL, OnUpdateLong, global_value, zend_hext_globals, hext_globals)
    STD_PHP_INI_ENTRY("hext.global_string", "foobar", PHP_INI_ALL, OnUpdateString, global_string, zend_hext_globals, hext_globals)
PHP_INI_END()
*/
/* }}} */

/* Remove the following function when you have successfully modified config.m4
   so that your module can be compiled into PHP, it exists only for testing
   purposes. */

/* Every user-visible function in PHP should document itself in the source */
/* {{{ proto string confirm_hext_compiled(string arg)
   Return a string to confirm that the module is compiled in */
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
/* }}} */
/* The previous line is meant for vim and emacs, so it can correctly fold and 
   unfold functions in source code. See the corresponding marks just before 
   function definition, where the functions purpose is also documented. Please 
   follow this convention for the convenience of others editing your code.
*/


/* {{{ php_hext_init_globals
 */
/* Uncomment this function if you have INI entries
static void php_hext_init_globals(zend_hext_globals *hext_globals)
{
	hext_globals->global_value = 0;
	hext_globals->global_string = NULL;
}
*/
/* }}} */

/* {{{ PHP_MINIT_FUNCTION
 */
PHP_MINIT_FUNCTION(hext)
{
	/* If you have INI entries, uncomment these lines 
	REGISTER_INI_ENTRIES();
	*/
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MSHUTDOWN_FUNCTION
 */
PHP_MSHUTDOWN_FUNCTION(hext)
{
	/* uncomment this line if you have INI entries
	UNREGISTER_INI_ENTRIES();
	*/
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request start */
/* {{{ PHP_RINIT_FUNCTION
 */
PHP_RINIT_FUNCTION(hext)
{
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request end */
/* {{{ PHP_RSHUTDOWN_FUNCTION
 */
PHP_RSHUTDOWN_FUNCTION(hext)
{
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(hext)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "hext support", "enabled");
	php_info_print_table_end();

	/* Remove comments if you have entries in php.ini
	DISPLAY_INI_ENTRIES();
	*/
}
/* }}} */

/* {{{ hext_functions[]
 *
 * Every user visible function must have an entry in hext_functions[].
 */
const zend_function_entry hext_functions[] = {
	PHP_FE(confirm_hext_compiled,	NULL)		/* For testing, remove later. */
	PHP_FE_END	/* Must be the last line in hext_functions[] */
};
/* }}} */

/* {{{ hext_module_entry
 */
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
/* }}} */

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
