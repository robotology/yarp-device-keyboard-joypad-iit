/*
 * Copyright (C) 2024 Istituto Italiano di Tecnologia (IIT)
 * All rights reserved.
 *
 * This software may be modified and distributed under the terms of the
 * BSD-2-Clause license. See the accompanying LICENSE file for details.
 */

#ifndef YARP_DEV_KEYBOARDJOYPAD_H
#define YARP_DEV_KEYBOARDJOYPAD_H

#include <memory>

#include <yarp/dev/DeviceDriver.h>
#include <yarp/dev/IJoypadController.h>
#include <yarp/os/PeriodicThread.h>
#include <yarp/dev/ServiceInterfaces.h>

namespace yarp {
    namespace dev {
        class KeyboardJoypad;
    }
}

class yarp::dev::KeyboardJoypad : public yarp::dev::DeviceDriver,
    public yarp::os::PeriodicThread,
    public yarp::dev::IService,
    public yarp::dev::IJoypadController
{
public:
    KeyboardJoypad();

    virtual ~KeyboardJoypad();

    // yarp::dev::DeviceDriver methods
    virtual bool open(yarp::os::Searchable& cfg) override;
    virtual bool close() override;

    // yarp::os::RateThread methods
    virtual bool threadInit() override;
    virtual void threadRelease() override;
    virtual void run() override;

    //  yarp::dev::IService methods
    virtual bool startService() override;
    virtual bool updateService() override;
    virtual bool stopService() override;

    // yarp::dev::IJoypadController methods
    virtual yarp::dev::ReturnValue getAxisCount(size_t& axis_count) override;
    virtual yarp::dev::ReturnValue getButtonCount(size_t& button_count) override;
    virtual yarp::dev::ReturnValue getTrackballCount(size_t& trackball_count) override;
    virtual yarp::dev::ReturnValue getHatCount(size_t& hat_count) override;
    virtual yarp::dev::ReturnValue getTouchSurfaceCount(size_t& touch_count) override;
    virtual yarp::dev::ReturnValue getStickCount(size_t& stick_count) override;
    virtual yarp::dev::ReturnValue getStickDoF(size_t stick_id, size_t& dof) override;
    virtual yarp::dev::ReturnValue getButton(size_t button_id, double& value) override;
    virtual yarp::dev::ReturnValue getTrackball(size_t trackball_id, yarp::dev::TrackballData& value) override;
    virtual yarp::dev::ReturnValue getHat(size_t hat_id, unsigned char& value) override;
    virtual yarp::dev::ReturnValue getAxis(size_t axis_id, double& value) override;
    virtual yarp::dev::ReturnValue getStick(size_t stick_id, yarp::dev::StickData& value, JoypadCtrl_coordinateMode coordinate_mode) override;
    virtual yarp::dev::ReturnValue getTouch(size_t touch_id, std::vector<yarp::dev::TouchData>& value) override;

private:

    class Impl;
    std::unique_ptr<Impl> m_pimpl;
};


#endif // YARP_DEV_KEYBOARDJOYPAD_H
