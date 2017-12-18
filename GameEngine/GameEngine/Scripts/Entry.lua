local applicationSettings = {
    title = "Game Engine",
    width = 1280,
    height = 720,
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
            name = "customEntity",
            path = "Scripts/script.lua"
        }     
    }
}

return applicationSettings 