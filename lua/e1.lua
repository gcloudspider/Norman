--Lua
--  - version 1.0
-- -------------------------------
-- Copyright (C) 2016-2016 by Norman (none_lih@163.com) 
-- Report bugs and download new versions at https//github.com/evely211
-- 
-- This library is distributed under the MIT License. See notice at the end of this file.
-- This work is based on POSIX，which is:
-- Copyright (C) 2016,by Norman
--
-- Lua动态类型语言 lua中8种基本类型:

local iValue = 10
local fValue = 10.2
local strValue = "Hello World"
local funcValue = print
local bValue = true
local nilValue = nil
local tbValue = {}

if type(iValue) == "number" then
    print("It is a number")
end

if type(fValue) == "number" then
    print("It is a number")
end

if type(strValue) == "string" then
    print("It is a string")
end

if type(funcValue) == "function" then
    print("It is a function")
end

if type(bValue) == "boolean" then
    print("It ia a boolean")
end

if type(nilValue) == "nil" then
    print("It is a nil")
end

if type(tbValue) == "table" then
    print("It is a table")
end


