//
// Created by Serge on 10.02.2020.
//

#ifndef REGISTERS_HARDWAREUARTTX_HPP
#define REGISTERS_HARDWAREUARTTX_HPP
#include "susudefs.hpp" //for __forceinline
#include "Stm32Fxx/STM32F411/hardwareuartbase.hpp" // for UartTx


template<typename UartModule, typename UartObservers>
struct HardwareUartTx
{
  using Uart = typename UartModule::Uart ;
  __forceinline template<typename T = typename UartModule::Base,
      class = typename std::enable_if_t<std::is_base_of<UartTxInterruptable, T>::value>>
  static void HandleInterrupt()
  {
    const bool DataRegisterEmpty = Uart::SR::TXE::DataRegisterEmpty::IsSet() ;
    const bool InterruptEnabled = Uart::CR1::TXEIE::InterruptWhenTXE::IsSet() ;
    if(DataRegisterEmpty && InterruptEnabled)
    {
      UartObservers::OnTxDataRegEmpty();
    }
  }
};

#endif //REGISTERS_HARDWAREUARTTX_HPP
