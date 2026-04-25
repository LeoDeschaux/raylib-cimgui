call emcc -c "D:/Software/Beef/BeefLibs/imgui-beef-quandini/cimgui/cimgui.cpp" -o wasm/cimgui.bc -emit-llvm

call emar rcs wasm/cimgui.a wasm/cimgui.bc 

call emcc -o wasm/cimgui.o -c imgui-master/imgui_tables.cpp -emit-llvm
call emcc -o wasm/imgui_demo.o -c imgui-master/imgui_demo.cpp -emit-llvm

call emar crs wasm/libimgui.a wasm/*.o

echo yay