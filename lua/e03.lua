--Loops

--for 变量 = 参数1,参数2,参数3 do
--循环体
--end

for i=1,5 do
    print("i is now"..i)
end

function f(x)
    local c1 = 4
    return c1;
end

for i=1,f(x) do
    print(i)
end
--步长为-1 参数1到参数2变化
for i=10,1,-1 do
    print(i)
end
