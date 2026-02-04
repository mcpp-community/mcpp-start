set_encodings("source:utf-8", "target:utf-8")
set_languages("c++23")

add_includedirs(".")

-- 设置自定义插件目录
add_plugindirs("d2x/buildtools")

includes("dslings/xmake.lua")