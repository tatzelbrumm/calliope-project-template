putreg(&NRF_CLOCK->TASKS_HFCLKSTART, "NRF_CLOCK->TASKS_HFCLKSTART     "); /*!< Start HFCLK clock source. */
putreg(&NRF_CLOCK->TASKS_HFCLKSTOP, "NRF_CLOCK->TASKS_HFCLKSTOP      "); /*!< Stop HFCLK clock source. */
putreg(&NRF_CLOCK->TASKS_LFCLKSTART, "NRF_CLOCK->TASKS_LFCLKSTART     "); /*!< Start LFCLK clock source. */
putreg(&NRF_CLOCK->TASKS_LFCLKSTOP, "NRF_CLOCK->TASKS_LFCLKSTOP      "); /*!< Stop LFCLK clock source. */
putreg(&NRF_CLOCK->TASKS_CAL, "NRF_CLOCK->TASKS_CAL            "); /*!< Start calibration of LFCLK RC oscillator. */
putreg(&NRF_CLOCK->TASKS_CTSTART, "NRF_CLOCK->TASKS_CTSTART        "); /*!< Start calibration timer. */
putreg(&NRF_CLOCK->TASKS_CTSTOP, "NRF_CLOCK->TASKS_CTSTOP         "); /*!< Stop calibration timer. */
putreg(&NRF_CLOCK->EVENTS_HFCLKSTARTED, "NRF_CLOCK->EVENTS_HFCLKSTARTED  "); /*!< HFCLK oscillator started. */
putreg(&NRF_CLOCK->EVENTS_LFCLKSTARTED, "NRF_CLOCK->EVENTS_LFCLKSTARTED  "); /*!< LFCLK oscillator started. */
putreg(&NRF_CLOCK->EVENTS_DONE, "NRF_CLOCK->EVENTS_DONE          "); /*!< Calibration of LFCLK RC oscillator completed. */
putreg(&NRF_CLOCK->EVENTS_CTTO, "NRF_CLOCK->EVENTS_CTTO          "); /*!< Calibration timer timeout. */
putreg(&NRF_CLOCK->INTENSET, "NRF_CLOCK->INTENSET             "); /*!< Interrupt enable set register. */
putreg(&NRF_CLOCK->INTENCLR, "NRF_CLOCK->INTENCLR             "); /*!< Interrupt enable clear register. */
putreg(&NRF_CLOCK->HFCLKRUN, "NRF_CLOCK->HFCLKRUN             "); /*!< Task HFCLKSTART trigger status. */
putreg(&NRF_CLOCK->HFCLKSTAT, "NRF_CLOCK->HFCLKSTAT            "); /*!< High frequency clock status. */
putreg(&NRF_CLOCK->LFCLKRUN, "NRF_CLOCK->LFCLKRUN             "); /*!< Task LFCLKSTART triggered status. */
putreg(&NRF_CLOCK->LFCLKSTAT, "NRF_CLOCK->LFCLKSTAT            "); /*!< Low frequency clock status. */
putreg(&NRF_CLOCK->LFCLKSRCCOPY, "NRF_CLOCK->LFCLKSRCCOPY         "); /*!< Clock source for the LFCLK clock, set when task LKCLKSTART is triggered. */
putreg(&NRF_CLOCK->LFCLKSRC, "NRF_CLOCK->LFCLKSRC             "); /*!< Clock source for the LFCLK clock. */
putreg(&NRF_CLOCK->CTIV, "NRF_CLOCK->CTIV                 "); /*!< Calibration timer interval. */
putreg(&NRF_CLOCK->XTALFREQ, "NRF_CLOCK->XTALFREQ             "); /*!< Crystal frequency. */