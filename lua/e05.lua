--Arrays
--
myData = {}
myData[0] = "foo"
myData[1] = 42

--Hash tables
myData["bar"] = "baz"

--Iterate through the
--structure

for key,value in pairs(myData) do
    print(key.."="..value)
end
