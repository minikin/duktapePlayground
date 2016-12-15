## Simple examples how to compile and use duktape 1.99.99

#### Clone repo to your computer or device

#### Add configuration _(optimize it for your needs)_ file if you need it to the duktape folder.

#### In terminal navigate to duktape folder and run command:

```
python tools/configure.py \
	--source-directory src-input \
	--config-metadata config/ \
	--option-file config.yaml \
	--output-directory /tmp/duk2
```

#### Copy all file in dir `/tmp/duk2` to preferred place.

#### Write you program

#### Compile program with make:

`make -f Makefile.hello`

It will produce some warnings due I disable a few options in `config.yaml`:

`
gcc -o hello  -Os -pedantic -std=c99 -Wall -fstrict-aliasing -fomit-frame-pointer -I./src   -UK_USE_FATAL_HANDLER src/duktape.c examples/hello/hello.c -lm
src/duktape.c:26138:21: warning: unused function 'duk__parse_string' [-Wunused-function]
DUK_LOCAL duk_ret_t duk__parse_string(duk_context *ctx, const char *str) {
                    ^
src/duktape.c:26769:21: warning: unused function 'duk__to_string_helper' [-Wunused-function]
DUK_LOCAL duk_ret_t duk__to_string_helper(duk_context *ctx, duk_small_uint_t flags) {
                    ^
src/duktape.c:26825:21: warning: unused function 'duk__get_part_helper' [-Wunused-function]
DUK_LOCAL duk_ret_t duk__get_part_helper(duk_context *ctx, duk_small_uint_t flags_and_idx) {
                    ^
src/duktape.c:26857:21: warning: unused function 'duk__set_part_helper' [-Wunused-function]
DUK_LOCAL duk_ret_t duk__set_part_helper(duk_context *ctx, duk_small_uint_t flags_and_maxnargs) {
                    ^
src/duktape.c:26982:16: warning: unused function 'duk__set_parts_from_args' [-Wunused-function]
DUK_LOCAL void duk__set_parts_from_args(duk_context *ctx, duk_double_t *dparts, duk_idx_t nargs) {
               ^
src/duktape.c:27157:28: warning: unused function 'duk__date_get_indirect_magic' [-Wunused-function]
DUK_LOCAL duk_small_uint_t duk__date_get_indirect_magic(duk_context *ctx) {
                           ^
6 warnings generated.
`

#### Run you program:

`./hello`

#### Minor comments by [Sami Vaarala](http://stackoverflow.com/questions/41146427/build-duktape-for-specific-platform-arm-32-arm-64/41153113#41153113):

 >Duktape duk_config.h detects the platform and target you're building for; Duktape never really builds "for all targets" as far as the resulting binary is concerned. So having multiple platforms in duk_config.h doesn't make the result any bigger for example.

 >You shouldn't need the values in your arm32_config.yaml. ARM32 should be detected automatically.
