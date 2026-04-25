call emcc -c rlcimgui.c -o wasm/rlcimgui.bc -emit-llvm -I"C:/raylib/raylib/src" -I"D:/Software/Beef/BeefLibs/imgui-beef-quandini/cimgui"
call emcc -o wasm/rlcimgui.o -c wasm/rlcimgui.bc

call emcc -c "D:/Software/Beef/BeefLibs/imgui-beef-quandini/cimgui/cimgui.cpp" -o wasm/cimgui.bc -emit-llvm
call emcc -o wasm/cimgui.o -c wasm/cimgui.bc


::imgui
call emcc -c "D:/Software/Beef/BeefLibs/imgui-beef-quandini/cimgui/imgui/imgui.cpp" -o wasm/imgui.bc -emit-llvm
call emcc -o wasm/imgui.o -c wasm/imgui.bc

::demo
call emcc -c "D:/Software/Beef/BeefLibs/imgui-beef-quandini/cimgui/imgui/imgui_demo.cpp" -o wasm/imgui_demo.bc -emit-llvm
call emcc -o wasm/imgui_demo.o -c wasm/imgui_demo.bc

::draw
call emcc -c "D:/Software/Beef/BeefLibs/imgui-beef-quandini/cimgui/imgui/imgui_draw.cpp" -o wasm/imgui_draw.bc -emit-llvm
call emcc -o wasm/imgui_draw.o -c wasm/imgui_draw.bc

::tables
call emcc -c "D:/Software/Beef/BeefLibs/imgui-beef-quandini/cimgui/imgui/imgui_tables.cpp" -o wasm/imgui_tables.bc -emit-llvm
call emcc -o wasm/imgui_tables.o -c wasm/imgui_tables.bc

::widgets
call emcc -c "D:/Software/Beef/BeefLibs/imgui-beef-quandini/cimgui/imgui/imgui_widgets.cpp" -o wasm/imgui_widgets.bc -emit-llvm
call emcc -o wasm/imgui_widgets.o -c wasm/imgui_widgets.bc

call emar crs wasm/librlcimgui.a wasm/*.o

echo yay
