//
// Created by Serge on 14.02.2020.
//

#ifndef REGISTERS_HARDWAREUARTRX_HPP
#define REGISTERS_HARDWAREUARTRX_HPP

#include "susudefs.hpp" //for __forceinline
#include "Stm32Fxx/STM32F411/hardwareuartbase.hpp" // for UartRx


template<typename UartModule, typename UartObservers>
struct HardwareUartRx
{
  using Uart = typename UartModule::Uart ;
  __forceinline template<typename T = typename UartModule::Base,
       class = typename std::enable_if_t<std::is_base_of<UartRxInterruptable, T>::value>>
  static void HandleInterrupt()
  {
    const bool DataRecieved = Uart::SR::RXNE::DataRecieved::IsSet() ;
    const bool InterruptEnabled = Uart::CR1::RXNEIE::InterruptWhenRXNE::IsSet() ;
    if(DataRecieved && InterruptEnabled)
    {
      UartObservers::OnRxData();
    }
  }
};

#endif //REGISTERS_HARDWAREUARTRX_HPP
