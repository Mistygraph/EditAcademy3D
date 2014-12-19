#version 330

// in vec3 VertexInEye;
//in vec3 Normal;

//uniform vec4 LightPosition;
//uniform vec3 Iads;
//
//uniform vec3 Kd;            // Diffuse reflectivity
//uniform vec3 Ka;            // Ambient reflectivity
//uniform vec3 Ks;            // Specular reflectivity
//uniform float Shininess;    // Specular shininess factor

layout( location = 0 ) out vec4 FragColor;

//vec3 ads()
//{
//    vec3 lightDir = normalize( vec3(LightPosition) - VertexInEye );
//    vec3 EyeDir = normalize(vec3(VertexInEye));
//    vec3 LightReflect = reflect( -lightDir, Normal );
//    
//    vec3 ambient = Iads * Ka;
//    
//    float lDotn = max( dot( lightDir , Normal ), 0.0 );
//    vec3 diffuse = Iads * Kd * lDotn;
//    vec3 specular = vec3(0.0);
//    if(lDotn > 0.0)
//        specular = Iads * Ks *
//        pow(max(dot(EyeDir, LightReflect), 0.0), Shininess);
//    return ambient + diffuse + specular;
//}

void main()
{
//    if(length(VertexInEye) < 0.0)
//        FragColor = vec4(1.0, 0.0, 0.0, 1.0);
    
    FragColor = vec4(0.0, 0.6, 0.8, 1.0);
}
