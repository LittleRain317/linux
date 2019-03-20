package org.omg.PortableInterceptor;


/**
* org/omg/PortableInterceptor/ObjectIdHelper.java .
* Generated by the IDL-to-Java compiler (portable), version "3.2"
* from /build/openjdk-lts-Ae5PRQ/openjdk-lts-10.0.2+13/src/java.corba/share/classes/org/omg/PortableInterceptor/Interceptors.idl
* Friday, November 16, 2018 at 3:15:35 PM Coordinated Universal Time
*/


/** Type of an object id. This provides the identity of a particular
   * object that was created by an object adapter.
   */
abstract public class ObjectIdHelper
{
  private static String  _id = "IDL:omg.org/PortableInterceptor/ObjectId:1.0";

  public static void insert (org.omg.CORBA.Any a, byte[] that)
  {
    org.omg.CORBA.portable.OutputStream out = a.create_output_stream ();
    a.type (type ());
    write (out, that);
    a.read_value (out.create_input_stream (), type ());
  }

  public static byte[] extract (org.omg.CORBA.Any a)
  {
    return read (a.create_input_stream ());
  }

  private static org.omg.CORBA.TypeCode __typeCode = null;
  synchronized public static org.omg.CORBA.TypeCode type ()
  {
    if (__typeCode == null)
    {
      __typeCode = org.omg.CORBA.ORB.init ().get_primitive_tc (org.omg.CORBA.TCKind.tk_octet);
      __typeCode = org.omg.CORBA.ORB.init ().create_sequence_tc (0, __typeCode);
      __typeCode = org.omg.CORBA.ORB.init ().create_alias_tc (org.omg.CORBA.OctetSeqHelper.id (), "OctetSeq", __typeCode);
      __typeCode = org.omg.CORBA.ORB.init ().create_alias_tc (org.omg.PortableInterceptor.ObjectIdHelper.id (), "ObjectId", __typeCode);
    }
    return __typeCode;
  }

  public static String id ()
  {
    return _id;
  }

  public static byte[] read (org.omg.CORBA.portable.InputStream istream)
  {
    byte value[] = null;
    value = org.omg.CORBA.OctetSeqHelper.read (istream);
    return value;
  }

  public static void write (org.omg.CORBA.portable.OutputStream ostream, byte[] value)
  {
    org.omg.CORBA.OctetSeqHelper.write (ostream, value);
  }

}
