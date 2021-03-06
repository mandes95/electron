// Copyright (c) 2013 GitHub, Inc.
// Use of this source code is governed by the MIT license that can be
// found in the LICENSE file.

#ifndef ATOM_BROWSER_API_ATOM_API_POWER_MONITOR_H_
#define ATOM_BROWSER_API_ATOM_API_POWER_MONITOR_H_

#include "atom/browser/api/event_emitter.h"
#include "base/compiler_specific.h"
#include "base/power_monitor/power_observer.h"
#include "native_mate/handle.h"

namespace atom {

namespace api {

class PowerMonitor : public mate::EventEmitter,
                     public base::PowerObserver {
 public:
  static v8::Handle<v8::Value> Create(v8::Isolate* isolate);

 protected:
  PowerMonitor();
  virtual ~PowerMonitor();

  // base::PowerObserver implementations:
  void OnPowerStateChange(bool on_battery_power) override;
  void OnSuspend() override;
  void OnResume() override;

 private:
  DISALLOW_COPY_AND_ASSIGN(PowerMonitor);
};

}  // namespace api

}  // namespace atom

#endif  // ATOM_BROWSER_API_ATOM_API_POWER_MONITOR_H_
