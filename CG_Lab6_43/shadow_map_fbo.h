#ifndef SHADOWMAPFBO_H
#define	SHADOWMAPFBO_H

#include <GL/glew.h>

class ShadowMapFBO
{
public:
    ShadowMapFBO();

    ~ShadowMapFBO();

    bool Init(unsigned int WindowWidth, unsigned int WindowHeight);

    void BindForWriting(GLenum CubeFace);
    //BindForWriting() теперь принимает enum для сторон куба
    void BindForReading(GLenum TextureUnit);
    
private:
    GLuint m_fbo;
    GLuint m_shadowMap;
    GLuint m_depth;
};

#endif	/* SHADOWMAPFBO_H */

