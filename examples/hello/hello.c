#include "duktape.h"

static duk_ret_t native_print(duk_context *ctx) {
		duk_push_string(ctx, " ");
		duk_insert(ctx, 0);
		duk_join(ctx, duk_get_top(ctx) - 1);
		printf("%s\n", duk_safe_to_string(ctx, -1));
		return 0;
}

int main(int argc, char *argv[]) {
	duk_context *ctx = duk_create_heap_default();

	duk_push_c_function(ctx, native_print, DUK_VARARGS);
	duk_put_global_string(ctx, "print");

	duk_eval_string(ctx, "print('Hello world!');");
	duk_destroy_heap(ctx);
	return 0;
}
