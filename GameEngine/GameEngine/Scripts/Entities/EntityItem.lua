--Local Class Variables
local num = 1;

--Entity Declare
entityItem = {
    information = {
        name = "Entity Name"
    },
    components = {
        componentList = {
            "graphicsComponent",
            "shaderComponent"
        },
        graphicsComponent = {
            filename = "Textures/Checker.png",
            isFlipped = false           
        },
        shaderComponent = {
            vertex = "Shaders/vertex.vs",
            frag = "Shaders/frag.fs"
        }
    },
    customScripts = {       
        update = function(entity)
            --Debug.Log("Update Function from Lua Script");
            entity:Move(num,0);
        end
    }
}

