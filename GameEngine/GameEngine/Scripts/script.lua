--[[testString = "This is the cats meow"
number = 69

Utility.printMessage("Go fuck yourself!")--]]

sumNumbers = function(a, b)
    Debug.Spacer();
    Debug.Log("Hello C++ from Lua");
    Debug.Spacer();
    return a + b
end

customEntity = {
    information = {
        name = "Other Custom Entity"
    },
    components = {
        componentList = {
            "graphicsComponent"
        },
        graphicsComponent = {
            filename = "image.png"           
        }
    }
}