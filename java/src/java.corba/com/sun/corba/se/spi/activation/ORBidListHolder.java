package com.sun.corba.se.spi.activation;


/**
* com/sun/corba/se/spi/activation/ORBidListHolder.java .
* Generated by the IDL-to-Java compiler (portable), version "3.2"
* from /build/openjdk-lts-Ae5PRQ/openjdk-lts-10.0.2+13/src/java.corba/share/classes/com/sun/corba/se/spi/activation/activation.idl
* Friday, November 16, 2018 at 3:15:30 PM Coordinated Universal Time
*/

public final class ORBidListHolder implements org.omg.CORBA.portable.Streamable
{
  public String value[] = null;

  public ORBidListHolder ()
  {
  }

  public ORBidListHolder (String[] initialValue)
  {
    value = initialValue;
  }

  public void _read (org.omg.CORBA.portable.InputStream i)
  {
    value = com.sun.corba.se.spi.activation.ORBidListHelper.read (i);
  }

  public void _write (org.omg.CORBA.portable.OutputStream o)
  {
    com.sun.corba.se.spi.activation.ORBidListHelper.write (o, value);
  }

  public org.omg.CORBA.TypeCode _type ()
  {
    return com.sun.corba.se.spi.activation.ORBidListHelper.type ();
  }

}
