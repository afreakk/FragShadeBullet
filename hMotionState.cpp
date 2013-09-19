#include "hMotionState.h"


hMotionState::hMotionState(Obj* RENDEROBJECT, const btTransform& startTrans,glm::vec2 offset
,const btTransform& centerOfMassOffset)
    :   m_graphicsWorldTrans(startTrans),
		m_centerOfMassOffset(centerOfMassOffset),
		m_startWorldTrans(startTrans),
		renderObject(RENDEROBJECT),
		renderOffset(offset),
		m_userPointer(0)
{
}
hMotionState::~hMotionState()
{
    //dtor
}
void hMotionState::getWorldTransform(btTransform& centerOfMassWorldTrans ) const
{

    centerOfMassWorldTrans = 	m_centerOfMassOffset.inverse() * m_graphicsWorldTrans ;

}
void hMotionState::setWorldTransform(const btTransform& centerOfMassWorldTrans)
{

    m_graphicsWorldTrans = centerOfMassWorldTrans * m_centerOfMassOffset ;
    btVector3 pos = m_graphicsWorldTrans.getOrigin();
    renderObject->setPosition(pos.x()+renderOffset.x, pos.y()+renderOffset.y);
}
