#ifndef HMOTIONSTATE_H
#define HMOTIONSTATE_H
#include <LinearMath/btMotionState.h>
#include "Obj.h"
#define PI 3.1415926535897932384626433832795
class hMotionState:public btMotionState
{
    public:
        hMotionState(Obj* RENDEROBJECT=0, const btTransform& startTrans = btTransform::getIdentity(),glm::vec2 offset=glm::vec2(0.0,0.0)
        ,const btTransform& centerOfMassOffset = btTransform::getIdentity());
		virtual void    getWorldTransform(btTransform& centerOfMassWorldTrans ) const;
        virtual void	setWorldTransform(const btTransform& centerOfMassWorldTrans);
        virtual ~hMotionState();
    protected:
    private:
        Obj* renderObject;
        btTransform m_graphicsWorldTrans;
        btTransform	m_centerOfMassOffset;
        btTransform m_startWorldTrans;
        glm::vec2 renderOffset;
        void*		m_userPointer;
};

#endif // HMOTIONSTATE_H
