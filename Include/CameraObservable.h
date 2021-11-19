#pragma once
#include "CameraObserver.h"

// TODO - implementovat. Není tøeba to implemetnovat až dále a ukládat CameraObsercer[] zde.

class CameraObservable
{
public:
	virtual void addCameraObserver(CameraObserver* obs) = 0;
	virtual void removeCameraObserver(CameraObserver* obs) = 0;

	virtual void notifyCameraObservers() = 0;
};