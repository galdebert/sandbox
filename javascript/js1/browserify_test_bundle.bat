@echo begin
cmd /c browserify browserify_test.js --s browserify_test_module -o browserify_test_bundle.js
@echo done

