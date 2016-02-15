--Table 'constructor'
--
myPolygon = {
    color = "blue",
    thickness = 2,
    npoints = 4,
    {x=0,y=0},
    {x=-10,y=0},
    {x=-5,y=4},
    {x=0,y=4}
}

--Print the color
print(myPolygon["color"])

print(myPolygon.color)

print(myPolygon[2].x)
