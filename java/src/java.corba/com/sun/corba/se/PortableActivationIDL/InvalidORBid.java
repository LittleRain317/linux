package com.sun.corba.se.PortableActivationIDL;


/**
* com/sun/corba/se/PortableActivationIDL/InvalidORBid.java .
* Generated by the IDL-to-Java compiler (portable), version "3.2"
* from /build/openjdk-lts-Ae5PRQ/openjdk-lts-10.0.2+13/src/java.corba/share/classes/com/sun/corba/se/PortableActivationIDL/activation.idl
* Friday, November 16, 2018 at 3:15:29 PM Coordinated Universal Time
*/

public final class InvalidORBid extends org.omg.CORBA.UserException
{

  public InvalidORBid ()
  {
    super(InvalidORBidHelper.id());
  } // ctor


  public InvalidORBid (String $reason)
  {
    super(InvalidORBidHelper.id() + "  " + $reason);
  } // ctor

} // class InvalidORBid
