@echo begin
cmd /c browserify -t [ babelify --presets [ react ] ] react_test.js --s react_test_module -o react_test_bundle.js
@echo done

