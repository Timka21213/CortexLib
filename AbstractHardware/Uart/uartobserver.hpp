//
// Created by Serge on 10.02.2020.
//

#ifndef REGISTERS_UARTOBSERVER_HPP
#define REGISTERS_UARTOBSERVER_HPP
#include "susudefs.hpp" //for __forceinline

template<typename... TObserver>
struct TransmitObservers
{
  __forceinline static void OnTxDataRegEmpty()
  {
    (TObserver::OnTransmit(), ...) ;
  }
} ;


template<typename... TObserver>
struct TransmitCompleteObservers
{
  __forceinline static void OnComplete()
  {
    (TObserver::OnTransmitComplete(), ...) ;
  }
} ;

template<typename... TObserver>
struct ReceiveObservers
{
  __forceinline static void OnRxData()
  {
    (TObserver::OnReceive(), ...) ;
  }
} ;
#endif //REGISTERS_UARTOBSERVER_HPP
