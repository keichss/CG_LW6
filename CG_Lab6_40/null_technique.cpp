#include <limits.h>
#include <string.h>

#include "null_technique.h"
#include "util.h"

static const char* pEffectFile = "C:/Users/ASUS/source/repos/CG_Lab6/shaders/shaders_40/null_technique.glsl";

NullTechnique::NullTechnique() : Technique(pEffectFile)
{   
}

bool NullTechnique::Init()
{
    if (!CompileProgram("NullTechnique")) {
        return false;
    }

    m_WVPLocation = GetUniformLocation("gWVP");

	if (m_WVPLocation == INVALID_UNIFORM_LOCATION) {
		return false;
	}

	return true;
}


void NullTechnique::SetWVP(const Matrix4f& WVP)
{
    glUniformMatrix4fv(m_WVPLocation, 1, GL_TRUE, (const GLfloat*)WVP.m);    
}

