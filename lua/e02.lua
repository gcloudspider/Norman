--function

function pythagorean(a,b)
local c2 = a^2+b^2   --local局部变量,不加local为全局变量 
return math.sqrt(c2)
end
print(pythagorean(3,4))
