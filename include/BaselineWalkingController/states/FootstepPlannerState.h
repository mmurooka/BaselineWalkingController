#pragma once

#include <BaselineFootstepPlanner/FootstepPlanner.h>

#include <BaselineWalkingController/State.h>

namespace BFP
{
/** \brief Configuration of environment for footstep planning set via mc_rtc configuration. */
struct FootstepEnvConfigMcRtc : public FootstepEnvConfig
{
  /** \brief Constructor.
      \param mcRtcConfig mc_rtc configuration
  */
  FootstepEnvConfigMcRtc(const mc_rtc::Configuration & mcRtcConfig = {});
};
} // namespace BFP

namespace BWC
{
/** \brief FSM state to walk with footstep planner. */
struct FootstepPlannerState : State
{
public:
  /** \brief Start. */
  void start(mc_control::fsm::Controller & ctl) override;

  /** \brief Run. */
  bool run(mc_control::fsm::Controller & ctl) override;

  /** \brief Teardown. */
  void teardown(mc_control::fsm::Controller & ctl) override;

protected:
  //! Footstep planner
  std::shared_ptr<BFP::FootstepPlanner> footstepPlanner_;

  //! Whether planning and walking is triggered
  bool triggered_ = false;

  //! Goal foot midpose (x [m], y [m], theta [rad])
  std::array<double, 3> goalFootMidpose_ = {0, 0, 0};
};
} // namespace BWC