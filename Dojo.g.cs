// <auto-generated>
// This code is generated by csbindgen.
// DON'T CHANGE THIS DIRECTLY.
// </auto-generated>
#pragma warning disable CS8500
#pragma warning disable CS8981
using System;
using System.Runtime.InteropServices;


namespace Dojo
{
    internal static unsafe partial class NativeMethods
    {
        const string __DllName = "nativelib";



        [DllImport(__DllName, EntryPoint = "client_new", CallingConvention = CallingConvention.Cdecl, ExactSpelling = true)]
        public static extern ToriiClient* client_new(byte* torii_url, byte* rpc_url, FieldElement* world, EntityQuery* entities, nuint entities_len, Error* error);

        [DllImport(__DllName, EntryPoint = "client_entity", CallingConvention = CallingConvention.Cdecl, ExactSpelling = true)]
        public static extern Ty* client_entity(ToriiClient* client, EntityQuery* entity, Error* error);

        [DllImport(__DllName, EntryPoint = "client_metadata", CallingConvention = CallingConvention.Cdecl, ExactSpelling = true)]
        public static extern WorldMetadata client_metadata(ToriiClient* client);

        [DllImport(__DllName, EntryPoint = "client_subscribed_entities", CallingConvention = CallingConvention.Cdecl, ExactSpelling = true)]
        public static extern CArray* client_subscribed_entities(ToriiClient* client);

        [DllImport(__DllName, EntryPoint = "client_start_subscription", CallingConvention = CallingConvention.Cdecl, ExactSpelling = true)]
        public static extern void client_start_subscription(ToriiClient* client, Error* error);

        [DllImport(__DllName, EntryPoint = "client_add_entities_to_sync", CallingConvention = CallingConvention.Cdecl, ExactSpelling = true)]
        public static extern void client_add_entities_to_sync(ToriiClient* client, EntityQuery* entities, nuint entities_len, Error* error);

        [DllImport(__DllName, EntryPoint = "client_remove_entities_to_sync", CallingConvention = CallingConvention.Cdecl, ExactSpelling = true)]
        public static extern void client_remove_entities_to_sync(ToriiClient* client, EntityQuery* entities, nuint entities_len, Error* error);

        [DllImport(__DllName, EntryPoint = "client_free", CallingConvention = CallingConvention.Cdecl, ExactSpelling = true)]
        public static extern void client_free(ToriiClient* client);


    }

    [StructLayout(LayoutKind.Sequential)]
    internal unsafe partial struct ToriiClient
    {
    }

    [StructLayout(LayoutKind.Sequential)]
    internal unsafe partial struct CArray
    {
        public T* data;
        public nuint data_len;
    }

    [StructLayout(LayoutKind.Sequential)]
    internal unsafe partial struct Error
    {
        public byte* message;
    }

    [StructLayout(LayoutKind.Sequential)]
    internal unsafe partial struct FieldElement
    {
        public fixed byte data[32];
    }

    [StructLayout(LayoutKind.Sequential)]
    internal unsafe partial struct EntityQuery
    {
        public byte* model;
        public Clause clause;
    }

    [StructLayout(LayoutKind.Sequential)]
    internal unsafe partial struct WorldMetadata
    {
        public FieldElement world_address;
        public FieldElement world_class_hash;
        public FieldElement executor_address;
        public FieldElement executor_class_hash;
        public CArray models;
    }


    internal enum Clause : uint
    {
        Keys,
        Attribute,
        Composite,
    }

    internal enum Ty : uint
    {
        TyPrimitive,
        TyStruct,
        TyEnum,
        TyTuple,
    }


}
    