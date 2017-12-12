--[[testString = "This is the cats meow"
number = 69

Utility.printMessage("Go fuck yourself!")--]]

sumNumbers = function(a, b)
    Debug.Spacer();
    Debug.Log("Hello C++ from Lua");
    Debug.Spacer();
    return a + b
end

entityItem = {
    information = {
        name = "Entity Name"
    },
    components = {
        GraphicsComponent = {
            filename = "image.png",
            z = 0,
            animated = false            
        }
    }
}