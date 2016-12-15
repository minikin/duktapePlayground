## Simple examples how to compile and use duktape 1.99.99

#### Clone [Duktape repo](https://github.com/svaarala/duktape) to your computer or device.

#### Add configuration `config.yaml` _(optimize it for your needs)_ file if you need it to the duktape folder.

#### In terminal navigate to duktape folder and run command:

```
python tools/configure.py \
	--source-directory src-input \
	--config-metadata config/ \
	--option-file config.yaml \
	--output-directory /tmp/duk2
```

#### Copy all file in dir `/tmp/duk2` to preferred place.

#### Write you program _(e.g. hello.c)_.  

#### Compile program with make:

`make -f Makefile.hello`

_It will produce some warnings due I disable  few options in `config.yaml`._

#### Run you program:

`./hello`

#### Minor comments by [Sami Vaarala](http://stackoverflow.com/questions/41146427/build-duktape-for-specific-platform-arm-32-arm-64/41153113#41153113):

 >Duktape duk_config.h detects the platform and target you're building for; Duktape never really builds "for all targets" as far as the resulting binary is concerned. So having multiple platforms in duk_config.h doesn't make the result any bigger for example.

 >You shouldn't need the values in your arm32_config.yaml. ARM32 should be detected automatically.

Thanks!
