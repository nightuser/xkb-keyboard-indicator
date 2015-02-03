#include <gio/gio.h>

#if defined (__ELF__) && ( __GNUC__ > 2 || (__GNUC__ == 2 && __GNUC_MINOR__ >= 6))
# define SECTION __attribute__ ((section (".gresource.xki"), aligned (8)))
#else
# define SECTION
#endif

static const SECTION union { const guint8 data[1072]; const double alignment; void * const ptr;}  xki_resource_data = { {
  0x47, 0x56, 0x61, 0x72, 0x69, 0x61, 0x6e, 0x74, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x18, 0x00, 0x00, 0x00, 0xc8, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x28, 0x06, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x01, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 
  0x04, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 
  0xed, 0xcb, 0xc5, 0x8a, 0x04, 0x00, 0x00, 0x00, 
  0xc8, 0x00, 0x00, 0x00, 0x04, 0x00, 0x4c, 0x00, 
  0xcc, 0x00, 0x00, 0x00, 0xd4, 0x00, 0x00, 0x00, 
  0xee, 0xe7, 0x11, 0xc2, 0x00, 0x00, 0x00, 0x00, 
  0xd4, 0x00, 0x00, 0x00, 0x07, 0x00, 0x76, 0x00, 
  0xe0, 0x00, 0x00, 0x00, 0xef, 0x01, 0x00, 0x00, 
  0xd4, 0xb5, 0x02, 0x00, 0xff, 0xff, 0xff, 0xff, 
  0xef, 0x01, 0x00, 0x00, 0x01, 0x00, 0x4c, 0x00, 
  0xf0, 0x01, 0x00, 0x00, 0xf4, 0x01, 0x00, 0x00, 
  0x71, 0x1e, 0xc2, 0xf2, 0x00, 0x00, 0x00, 0x00, 
  0xf4, 0x01, 0x00, 0x00, 0x0f, 0x00, 0x76, 0x00, 
  0x08, 0x02, 0x00, 0x00, 0x17, 0x04, 0x00, 0x00, 
  0x92, 0x30, 0x98, 0x0f, 0x05, 0x00, 0x00, 0x00, 
  0x17, 0x04, 0x00, 0x00, 0x0a, 0x00, 0x4c, 0x00, 
  0x24, 0x04, 0x00, 0x00, 0x28, 0x04, 0x00, 0x00, 
  0x8a, 0xc9, 0x78, 0x7c, 0x02, 0x00, 0x00, 0x00, 
  0x28, 0x04, 0x00, 0x00, 0x03, 0x00, 0x4c, 0x00, 
  0x2c, 0x04, 0x00, 0x00, 0x30, 0x04, 0x00, 0x00, 
  0x78, 0x6b, 0x69, 0x2f, 0x03, 0x00, 0x00, 0x00, 
  0x01, 0x00, 0x00, 0x00, 0x6d, 0x65, 0x6e, 0x75, 
  0x2e, 0x75, 0x69, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x9c, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 
  0x78, 0xda, 0x9d, 0x90, 0xb1, 0x0e, 0xc2, 0x30, 
  0x0c, 0x44, 0x77, 0xbe, 0x22, 0xf2, 0x4e, 0x03, 
  0x1b, 0x43, 0xda, 0x8a, 0x05, 0x89, 0x0d, 0x24, 
  0xf8, 0x00, 0xb7, 0x35, 0x28, 0x52, 0x9a, 0x84, 
  0xd4, 0x41, 0xf0, 0xf7, 0xa4, 0x45, 0xa2, 0x1d, 
  0xca, 0x00, 0x9b, 0xcf, 0xd6, 0x9d, 0x4f, 0x4f, 
  0x95, 0x8f, 0xd6, 0x88, 0x3b, 0x85, 0x4e, 0x3b, 
  0x9b, 0xc3, 0x3a, 0x5b, 0x81, 0x20, 0x5b, 0xbb, 
  0x46, 0xdb, 0x6b, 0x0e, 0xe7, 0xd3, 0x6e, 0xb9, 
  0x81, 0xb2, 0x58, 0x28, 0x6d, 0x99, 0xc2, 0x05, 
  0x6b, 0x2a, 0x16, 0x42, 0xa8, 0x96, 0x6c, 0x14, 
  0xba, 0xc9, 0x61, 0x6f, 0x1b, 0x5d, 0x23, 0xbb, 
  0x70, 0x70, 0x3e, 0x7a, 0x18, 0x8e, 0x1d, 0xd5, 
  0x9c, 0xc2, 0xfa, 0x39, 0x29, 0xcd, 0xd4, 0xbe, 
  0xc7, 0x24, 0x90, 0x39, 0xe8, 0x2a, 0x32, 0x09, 
  0x8b, 0x2d, 0xe5, 0x60, 0xb0, 0x22, 0x03, 0x82, 
  0x03, 0xda, 0xce, 0x20, 0x63, 0x65, 0xd2, 0xf2, 
  0x49, 0x1d, 0x14, 0xdb, 0xca, 0x45, 0x56, 0xf2, 
  0x63, 0xf8, 0x1a, 0x81, 0xc3, 0x33, 0x28, 0xd0, 
  0xfb, 0x0c, 0x67, 0x4d, 0x4a, 0x8e, 0x1d, 0xfe, 
  0xad, 0x73, 0x8c, 0xfa, 0xe7, 0x36, 0xb7, 0x39, 
  0xcf, 0x58, 0x46, 0xc9, 0x09, 0x28, 0x25, 0x7b, 
  0xa4, 0x89, 0xb3, 0x9c, 0x80, 0x7e, 0x01, 0x4c, 
  0x83, 0x83, 0xfa, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x28, 0x75, 0x75, 0x61, 0x79, 0x29, 0x2f, 
  0x05, 0x00, 0x00, 0x00, 0x61, 0x62, 0x6f, 0x75, 
  0x74, 0x2d, 0x64, 0x69, 0x61, 0x6c, 0x6f, 0x67, 
  0x2e, 0x75, 0x69, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x21, 0x02, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 
  0x78, 0xda, 0x85, 0x91, 0x4f, 0x4f, 0xc3, 0x30, 
  0x0c, 0xc5, 0xef, 0xfb, 0x14, 0x51, 0x0e, 0xbb, 
  0xed, 0xdf, 0x0d, 0xb1, 0xb6, 0x63, 0x12, 0x62, 
  0x27, 0x4e, 0x8c, 0x73, 0xe5, 0x26, 0x5e, 0x1b, 
  0x96, 0xc5, 0x95, 0xe3, 0x96, 0x85, 0x4f, 0x4f, 
  0x37, 0x40, 0x02, 0x69, 0xa8, 0x57, 0xfb, 0xfd, 
  0x9e, 0x9f, 0xf5, 0xb2, 0xcd, 0xf9, 0xe4, 0x55, 
  0x8f, 0x1c, 0x1d, 0x85, 0x5c, 0xaf, 0xe6, 0x4b, 
  0xad, 0x30, 0x18, 0xb2, 0x2e, 0xd4, 0xb9, 0x7e, 
  0xdd, 0x3f, 0xcd, 0xee, 0xf4, 0xa6, 0x98, 0x64, 
  0x2e, 0x08, 0xf2, 0x01, 0x0c, 0x16, 0x13, 0xa5, 
  0x32, 0xaa, 0xde, 0xd0, 0x88, 0x32, 0x1e, 0x62, 
  0xcc, 0xf5, 0x4e, 0x8e, 0xcf, 0x18, 0x23, 0xd4, 
  0xf8, 0xe8, 0xc0, 0x53, 0xad, 0x95, 0xb3, 0xb9, 
  0xde, 0x56, 0xd4, 0xc9, 0xf7, 0xe0, 0x02, 0x0d, 
  0x58, 0xcb, 0xd4, 0x22, 0x4b, 0x52, 0x01, 0x4e, 
  0x98, 0x6b, 0x71, 0xe2, 0x51, 0x2b, 0x61, 0x08, 
  0xd1, 0x83, 0x40, 0xe5, 0x87, 0x61, 0xc2, 0xa8, 
  0x8b, 0x2b, 0x9b, 0x2d, 0x7e, 0xf4, 0xb7, 0x71, 
  0x8b, 0x51, 0x98, 0x52, 0xf9, 0xee, 0xa4, 0x29, 
  0x5b, 0x60, 0x0c, 0xa2, 0x8b, 0x3d, 0x77, 0x38, 
  0x06, 0x4a, 0x6a, 0xb1, 0x6c, 0xdc, 0x45, 0x6e, 
  0xaf, 0xf9, 0xc6, 0x80, 0xaa, 0x13, 0xa1, 0x30, 
  0xe4, 0x32, 0x9e, 0xe2, 0xb8, 0x3d, 0x9e, 0xe5, 
  0xe6, 0x57, 0xe7, 0x63, 0x35, 0x3b, 0x62, 0xaa, 
  0x08, 0xd8, 0xce, 0x5c, 0xb0, 0xce, 0x80, 0x10, 
  0xab, 0xe5, 0x7c, 0x35, 0x66, 0x19, 0xd1, 0x50, 
  0xb0, 0xc0, 0xa9, 0xfc, 0xd7, 0x7c, 0xdb, 0x49, 
  0x43, 0x7c, 0xaf, 0x5e, 0xfa, 0x34, 0xb8, 0x0e, 
  0xcb, 0x5e, 0xed, 0x38, 0xc1, 0x47, 0xa0, 0x5e, 
  0x4d, 0xbd, 0xac, 0x83, 0xab, 0x1b, 0xe9, 0x22, 
  0xf2, 0x43, 0x82, 0x39, 0x77, 0xd3, 0x5a, 0xd6, 
  0x7f, 0xaf, 0x66, 0x8b, 0xaf, 0x56, 0x87, 0xb2, 
  0x17, 0xbf, 0xda, 0xfe, 0x04, 0xa5, 0x52, 0xbd, 
  0xc1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x28, 0x75, 0x75, 0x61, 0x79, 0x29, 0x6e, 
  0x69, 0x67, 0x68, 0x74, 0x75, 0x73, 0x65, 0x72, 
  0x2f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x72, 0x75, 0x2f, 0x00, 0x04, 0x00, 0x00, 0x00
} };

static GStaticResource static_resource = { xki_resource_data.data, sizeof (xki_resource_data.data), NULL, NULL, NULL };
extern GResource *xki_get_resource (void);
GResource *xki_get_resource (void)
{
  return g_static_resource_get_resource (&static_resource);
}
/*
  If G_HAS_CONSTRUCTORS is true then the compiler support *both* constructors and
  destructors, in a sane way, including e.g. on library unload. If not you're on
  your own.

  Some compilers need #pragma to handle this, which does not work with macros,
  so the way you need to use this is (for constructors):

  #ifdef G_DEFINE_CONSTRUCTOR_NEEDS_PRAGMA
  #pragma G_DEFINE_CONSTRUCTOR_PRAGMA_ARGS(my_constructor)
  #endif
  G_DEFINE_CONSTRUCTOR(my_constructor)
  static void my_constructor(void) {
   ...
  }

*/

#if  __GNUC__ > 2 || (__GNUC__ == 2 && __GNUC_MINOR__ >= 7)

#define G_HAS_CONSTRUCTORS 1

#define G_DEFINE_CONSTRUCTOR(_func) static void __attribute__((constructor)) _func (void);
#define G_DEFINE_DESTRUCTOR(_func) static void __attribute__((destructor)) _func (void);

#elif defined (_MSC_VER) && (_MSC_VER >= 1500)
/* Visual studio 2008 and later has _Pragma */

#define G_HAS_CONSTRUCTORS 1

#define G_DEFINE_CONSTRUCTOR(_func) \
  static void _func(void); \
  static int _func ## _wrapper(void) { _func(); return 0; } \
  __pragma(section(".CRT$XCU",read)) \
  __declspec(allocate(".CRT$XCU")) static int (* _array ## _func)(void) = _func ## _wrapper;

#define G_DEFINE_DESTRUCTOR(_func) \
  static void _func(void); \
  static int _func ## _constructor(void) { atexit (_func); return 0; } \
  __pragma(section(".CRT$XCU",read)) \
  __declspec(allocate(".CRT$XCU")) static int (* _array ## _func)(void) = _func ## _constructor;

#elif defined (_MSC_VER)

#define G_HAS_CONSTRUCTORS 1

/* Pre Visual studio 2008 must use #pragma section */
#define G_DEFINE_CONSTRUCTOR_NEEDS_PRAGMA 1
#define G_DEFINE_DESTRUCTOR_NEEDS_PRAGMA 1

#define G_DEFINE_CONSTRUCTOR_PRAGMA_ARGS(_func) \
  section(".CRT$XCU",read)
#define G_DEFINE_CONSTRUCTOR(_func) \
  static void _func(void); \
  static int _func ## _wrapper(void) { _func(); return 0; } \
  __declspec(allocate(".CRT$XCU")) static int (*p)(void) = _func ## _wrapper;

#define G_DEFINE_DESTRUCTOR_PRAGMA_ARGS(_func) \
  section(".CRT$XCU",read)
#define G_DEFINE_DESTRUCTOR(_func) \
  static void _func(void); \
  static int _func ## _constructor(void) { atexit (_func); return 0; } \
  __declspec(allocate(".CRT$XCU")) static int (* _array ## _func)(void) = _func ## _constructor;

#elif defined(__SUNPRO_C)

/* This is not tested, but i believe it should work, based on:
 * http://opensource.apple.com/source/OpenSSL098/OpenSSL098-35/src/fips/fips_premain.c
 */

#define G_HAS_CONSTRUCTORS 1

#define G_DEFINE_CONSTRUCTOR_NEEDS_PRAGMA 1
#define G_DEFINE_DESTRUCTOR_NEEDS_PRAGMA 1

#define G_DEFINE_CONSTRUCTOR_PRAGMA_ARGS(_func) \
  init(_func)
#define G_DEFINE_CONSTRUCTOR(_func) \
  static void _func(void);

#define G_DEFINE_DESTRUCTOR_PRAGMA_ARGS(_func) \
  fini(_func)
#define G_DEFINE_DESTRUCTOR(_func) \
  static void _func(void);

#else

/* constructors not supported for this compiler */

#endif


#ifdef G_HAS_CONSTRUCTORS

#ifdef G_DEFINE_CONSTRUCTOR_NEEDS_PRAGMA
#pragma G_DEFINE_CONSTRUCTOR_PRAGMA_ARGS(resource_constructor)
#endif
G_DEFINE_CONSTRUCTOR(resource_constructor)
#ifdef G_DEFINE_DESTRUCTOR_NEEDS_PRAGMA
#pragma G_DEFINE_DESTRUCTOR_PRAGMA_ARGS(resource_destructor)
#endif
G_DEFINE_DESTRUCTOR(resource_destructor)

#else
#warning "Constructor not supported on this compiler, linking in resources will not work"
#endif

static void resource_constructor (void)
{
  g_static_resource_init (&static_resource);
}

static void resource_destructor (void)
{
  g_static_resource_fini (&static_resource);
}
