
#include <nginx.h>
#include <ngx_config.h>
#include <ngx_core.h>
#include <ngx_http.h>

ngx_module_t ngx_http_mymodule_module;

static ngx_int_t ngx_http_mymodule_handler(ngx_http_request_t *r)
{
  if (r->main->internal)
  {
    return NGX_DECLINED;
  }

  // printf("\n--- mymodule:\n");

  // r->main->internal = 1;

  // ngx_table_elt_t *h;
  // h = ngx_list_push(&r->headers_out.headers);
  // h->hash = 1;

  // ngx_str_set(&h->key, "X-asdasd-Tutorial");

  // if (!r->cache || !r->cache->key)
  //   printf("cache was not set\n");
  // else
  // {
  //   char hex[sizeof(r->cache->key)];
  //   for (ulong i = 0; i < sizeof(r->cache->key); i++)
  //     sprintf(hex + 2 * i, "%.2x", r->cache->key[i]);

  //   printf("%s\n", hex);
  //   // ngx_str_set(&h->value, hex);
  // }

  // // ngx_str_set(&h->value, "asdf World!");

  // printf("\n");

  return NGX_DECLINED;
}

static ngx_int_t ngx_http_mymodule_init(ngx_conf_t *cf)
{
  ngx_http_handler_pt *h;
  ngx_http_core_main_conf_t *cmcf;

  cmcf = ngx_http_conf_get_module_main_conf(cf, ngx_http_core_module);

  // h = ngx_array_push(&cmcf->phases[NGX_HTTP_CONTENT_PHASE].handlers);
  h = ngx_array_push(&cmcf->phases[NGX_HTTP_LOG_PHASE].handlers);

  if (h == NULL)
  {
    return NGX_ERROR;
  }

  *h = ngx_http_mymodule_handler;

  return NGX_OK;
}

static ngx_http_module_t ngx_http_mymodule_module_ctx = {
    NULL,                   /* preconfiguration */
    ngx_http_mymodule_init, /* postconfiguration */
    NULL,                   /* create main configuration */
    NULL,                   /* init main configuration */
    NULL,                   /* create server configuration */
    NULL,                   /* merge server configuration */
    NULL,                   /* create location configuration */
    NULL                    /* merge location configuration */
};

ngx_module_t ngx_http_mymodule_module = {
    NGX_MODULE_V1,
    &ngx_http_mymodule_module_ctx, /* module context */
    NULL,                          /* module directives */
    NGX_HTTP_MODULE,               /* module type */
    NULL,                          /* init master */
    NULL,                          /* init module */
    NULL,                          /* init process */
    NULL,                          /* init thread */
    NULL,                          /* exit thread */
    NULL,                          /* exit process */
    NULL,                          /* exit master */
    NGX_MODULE_V1_PADDING};
