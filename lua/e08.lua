--Function can take a 
--variable number of
--arguments
--
--...表示参数的数量不定
--参数将自动存储到arg的table中
--arg.n中存放参数个数.arg[]加下标就可以遍历所有参数
--function funky_print(...)
--    for i=1,arg.n do
--        print("FuNkY:"..arg[i])
--    end
--end

function print_contents(t)
    for k,v in pairs(t) do
        print(k.."="..v)
    end
end

funky_print("one","two")

print_contents{x=10,y=20}
