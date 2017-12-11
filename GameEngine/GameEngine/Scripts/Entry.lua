local applicationSettings = {
    title = "Game Engine",
    width = 640,
    height = 480,
    scripts = {
        --"Scripts/script.lua",
        --"Scripts/secondScript.lua"
    },
    entities = {
        {
            name = "entityItem",
            path = "Scripts/Entities/EntityItem.lua"
        },
        {
            name = "sumNumbers",
            path = "Scripts/script.lua"
        }     
    }
}

return applicationSettings 