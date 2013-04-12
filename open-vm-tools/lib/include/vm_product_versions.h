/*********************************************************
 * Copyright (C) 1998-2010 VMware, Inc. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published
 * by the Free Software Foundation version 2.1 and no later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE.  See the Lesser GNU General Public
 * License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin St, Fifth Floor, Boston, MA  02110-1301 USA.
 *
 *********************************************************/
#ifndef VM_PRODUCT_VERSIONS_H
#define VM_PRODUCT_VERSIONS_H

/*
 * NOTE: Some of the macro expansions in this file require information
 *       from the generated file, 'buildNumber.h'.  For those
 *       expansions, and for those expansions only, you must include
 *       "vm_version.h" first.
 */

/*
 * Used in .rc files on the Win32 platform. We must use PRODUCT_BUILD_NUMBER
 * in numeric Win32 version numbers to stay below the 65k (circa) limit.
 *
 * When building the Tools, we make an effort to follow the "internal" Tools
 * version. Otherwise we use a hard-coded value for Workstation and a different
 * hard-coded value for every other product.
 */
#if defined(VMX86_DESKTOP)
   #define PRODUCT_VERSION    9,0,0,PRODUCT_BUILD_NUMBER_NUMERIC  /* WORKSTATION_VERSION_NUMBER below has to match this */
#elif defined(VMX86_TOOLS)
   #define PRODUCT_VERSION    TOOLS_VERSION_EXT_CURRENT_CSV
#elif defined(VMX86_VCB)
   #define PRODUCT_VERSION    1,0,0,PRODUCT_BUILD_NUMBER_NUMERIC
#elif defined(VMX86_VLICENSE)
   #define PRODUCT_VERSION    1,1,5,PRODUCT_BUILD_NUMBER_NUMERIC
#elif defined(VMX86_VPX)
   /* this should be kept in sync with the corresponding vpx branch. */
   #define PRODUCT_VERSION    6,0,0,PRODUCT_BUILD_NUMBER_NUMERIC
#elif defined(VMX86_BOOMERANG)
   #define PRODUCT_VERSION    1,0,0,PRODUCT_BUILD_NUMBER_NUMERIC
#elif defined(VMX86_VIEW)
   #define PRODUCT_VERSION    0,0,0,PRODUCT_BUILD_NUMBER_NUMERIC
#else
   #define PRODUCT_VERSION    5,0,0,PRODUCT_BUILD_NUMBER_NUMERIC  /* PLAYER_VERSION_NUMBER below has to match this */
#endif

/*
 * The VIE components are shared by different products and may be updated by newer
 * installers. Since the installer replaces the component files based on the version
 * resource, it's important that the file version be monotonically increasing. As
 * a result, these components need their own file version number that is
 * independent of the VMX86_XXX macros. This goes into the FILEVERSION property of
 * the version resources. The first release of this stuff was with VPX which had a
 * FILEVERSION of 1,0,0,PRODUCT_BUILD_NUMBER_NUMERIC
 *
 * P2VA 2.0     : 2,1,2
 * VPX 1.2      : 2,1,3
 * V2V 1.0      : 2.2.0
 * SYSIMAGE 1.0 : 2.2.1 or later (TBD)
 * Symantec     : 2.2.2 7/2005
 * VC 2.0       : 2.2.3
 * P2V 2.1      : 2.2.4 (also used for WS55 betas and RC)
 * V2V 1.5      : 2.2.5 V2V 1.5 released with WS55
 * WS 5.1       : 2.2.5 to be set when WS55 branches
 * VCB 1.0      : e.x.p esx-dali: first release with vmacore + vstor3Bus
 * VCB 1.0.1    : 3.0.1 includes security fix for registry alteration vulnerability
 * VCB 1.1      : 3.1
 * VMI 2.0      : 3.1.0
 * P2VA 3.0     : 3.?.?
 */
#define VIE_FILEVERSION 6,0,0,PRODUCT_BUILD_NUMBER_NUMERIC

/*
 * This string can be a little more "free form".  The license
 * manager doesn't depend on it.  This is the version that will
 * be used by the build process, the UI, etc.  Things people see.
 *
 * If platforms are on different version numbers, manage it here.
 *
 * Manage version numbers for each product here.
 *
 *  NOTE:  BE AWARE that Scons/Makefiles and build scripts depend
 *         on these defines.
 *
 *         In particular, only the first quoted token after the
 *         macro name will be used for the macro value by the build
 *         system.  Also, if VERSION_MAJOR, VERSION_MINOR, and
 *         VERSION_MAINT macros are defined, they override the
 *         VERSION macro in the build system.
 *
 */

/*
 * When updating the ESX_VERSION* and ESX_RELEASE* macros, you will also
 * need to update:
 *
 *   > bora/support/gobuild/targets/server.py
 *   > console-os26/SOURCES/kernel-2.6.spec
 *
 * Rules for updating the ESX_RELEASE_* macros:
 *
 * Set UPDATE to 0 for all experimental/prerelease/and initial major and minor
 * releases.  Increment update for each update release.
 *
 * Set PATCH to 0 for all experimental builds.  Increment it for each build
 * that will be delivered externally.
 *
 * THEORETICAL EXAMPLES:
 *
 * 4.0.0-0.0: experimental version
 * 4.0.0-0.1: beta 1
 * 4.0.0-0.2: beta 2
 * 4.0.0-0.3; rc1
 * 4.0.0-0.4: GA
 * 4.0.0-0.5: patch 1
 * 4.0.0-0.6: patch 2
 * 4.0.0-1.7: update 1
 * 4.0.0-1.8: patch 3
 */
#define ESX_VERSION_MAJOR "6"
#define ESX_VERSION_MINOR "0"
#define ESX_VERSION_MAINT "0"
#define ESX_VERSION ESX_VERSION_MAJOR "." ESX_VERSION_MINOR "." \
                    ESX_VERSION_MAINT
#define ESX_VERSION_THIRD_PARTY ESX_VERSION_MAJOR ESX_VERSION_MINOR \
                                ESX_VERSION_MAINT
#define ESX_RELEASE_UPDATE "0" /* 0 = Pre-release/GA, 1 = Update 1 */
#define ESX_RELEASE_PATCH "0"  /* 0 = experimental */
#define ESX_RELEASE ESX_RELEASE_UPDATE "." ESX_RELEASE_PATCH
#define VMSERVER_VERSION "e.x.p"
#define WORKSTATION_VERSION_NUMBER "9.0.0" /* this version number should always match real WS version number */
#define WORKSTATION_VERSION "e.x.p"
#define WORKSTATION_RELEASE_DESCRIPTION ""
#define WORKSTATION_ENTERPRISE_VERSION "e.x.p"
#define WSX_SERVER_VERSION_NUMBER "1.0.0"
#define WSX_SERVER_VERSION "e.x.p"
#define ACE_MANAGEMENT_SERVER_VERSION "e.x.p"
#define MUI_VERSION "4.1.0"
#define CONSOLE_VERSION "4.1.0"
#define P2V_VERSION "e.x.p"
#define P2V_FILE_VERSION 3,0,0,0
#define PLAYER_VERSION_NUMBER "5.0.0" /* this version number should always match real Player version number */
#define PLAYER_VERSION "e.x.p"

/*
 * When updating FUSION_VERSION from e.x.p to GA, you will also need to update
 * lastVersion{Major,Minor,Patch} in bora/scons/package/fusion/fusion.sc
 * which controls what versions are allowed to automatically update for free.
 */
#define FUSION_VERSION "e.x.p"

#define BOOMERANG_VERSION "e.x.p"

// These must match VIE_FILEVERSION above
#define SYSIMAGE_VERSION "6.0.0"
#define SYSIMAGE_FILE_VERSION VIE_FILEVERSION

#define VCB_VERSION "4.0.0"
#define VCB_FILE_VERSION 4,0,0,0
#define VIM_VERSION "6.0.0"

// Put VPX_VERSION first, because vpx/make/defs.mk doesn't check for suffix.
#define VPX_VERSION "6.0.0"
#define VPX_VERSION_MAJOR "6"
#define VPX_VERSION_MINOR "0"
#define VPX_VERSION_MAINT "0"
#define VPX_VERSION_THIRD_PARTY VPX_VERSION_MAJOR VPX_VERSION_MINOR \
                                VPX_VERSION_MAINT
#define VPX_RELEASE_UPDATE "0" /* 0 = Pre-release/GA, 1 = Update 1 */
#define VPX_RELEASE_PATCH "0"  /* 0 = experimental */
#define VPX_RELEASE VPX_RELEASE_UPDATE "." VPX_RELEASE_PATCH

#define SVA_VERSION "1.0.0"
#define SSO_VERSION "1.0.0"
#define WBC_VERSION "5.1.0"
#define SDK_VERSION "4.1.0"
#define FOUNDRY_VERSION "1.12.0"
#define FOUNDRY_FILE_VERSION 1,12,0,PRODUCT_BUILD_NUMBER_NUMERIC
#define VMLS_VERSION "e.x.p"
#define VLICENSE_VERSION "1.1.5"
#define DDK_VERSION "e.x.p"
#define VIPERL_VERSION "1.1.0"
#define RCLI_VERSION "6.0.0"
#define VDM_VERSION "e.x.p"
#define VMSAFE_VERSION        "1.2.0"
#define VMSAFE_FILE_VERSION    1,2,0,PRODUCT_BUILD_NUMBER_NUMERIC
#define NETDUMP_VERSION        "5.1.0"
#define NETDUMP_FILE_VERSION    5,1,0,PRODUCT_BUILD_NUMBER_NUMERIC
#define VDDK_VERSION          "6.0.0"
#define VDDK_FILE_VERSION      6,0,0,PRODUCT_BUILD_NUMBER_NUMERIC
#define OVFTOOL_VERSION "e.x.p"
#define OVFTOOL_FILE_VERSION 3,0,1,PRODUCT_BUILD_NUMBER_NUMERIC
#define VDM_CLIENT_VERSION "e.x.p"
#define VGAUTH_VERSION "e.x.p"
#define VIEWY_VERSION "e.x.p"
#define VMCFSDK_VERSION "e.x.p"
#define PCOIP_VERSION "e.x.p"
#define VIEW_VERSION "0.0.0"
#define HOSTD_VERSION "e.x.p"
#define RECOVERYLIBS_VERSION "2.0.0"
#define PRECHECK_VERSION "e.x.p"


#ifndef MAKESTR
#define MAKESTR(x) #x
#define XSTR(x) MAKESTR(x)
#endif

// This extra version define is here so the Makefiles can easily pick it up.
// See the VMRC_PLUGIN_VERSION section in /mk/defs-onetime.mk

#define VMRC_PLUGIN_VERSION_MAJOR 5
#define VMRC_PLUGIN_VERSION_MINOR 1
#define VMRC_PLUGIN_VERSION_Z     0

/*
 * TODO: figure out why the following breaks linux installer
 * #define VMRC_PLUGIN_VERSION_NUMBER       \
 *         XSTR(VMRC_PLUGIN_VERSION_MAJOR) "." XSTR(VMRC_PLUGIN_VERSION_MINOR) "." XSTR(VMRC_PLUGIN_VERSION_Z)
 */
#define VMRC_PLUGIN_VERSION_NUMBER "5.1.0"

/* this version number should always match real VMRC & plugin version number */
#define VMRC_VERSION VMRC_PLUGIN_VERSION_NUMBER

#define VMRC_PLUGIN_VERSION_BASE  VMRC_PLUGIN_VERSION_MAJOR.VMRC_PLUGIN_VERSION_MINOR

#define VMRC_PLUGIN_VERSION       \
        XSTR(VMRC_PLUGIN_VERSION_BASE) "." XSTR(VMRC_PLUGIN_VERSION_Z) "." BUILD_NUMBER_NUMERIC_STRING
#define VMRC_PLUGIN_VERSION_COMMAS \
        VMRC_PLUGIN_VERSION_MAJOR,VMRC_PLUGIN_VERSION_MINOR,0,PRODUCT_BUILD_NUMBER_NUMERIC

/*
 * The current Tools version, derived from vm_tools_version.h. Do not modify this.
 */
#define TOOLS_VERSION TOOLS_VERSION_CURRENT_STR

#ifdef VMX86_VPX
#define VIM_API_TYPE "VirtualCenter"
#else
#define VIM_API_TYPE "HostAgent"
#endif

#define VIM_EESX_PRODUCT_LINE_ID "embeddedEsx"
#define VIM_ESX_PRODUCT_LINE_ID "esx"
#define VIM_WS_PRODUCT_LINE_ID "ws"

#if defined(VMX86_SERVER)
#  define PRODUCT_VERSION_NUMBER ESX_VERSION
#elif defined(VMX86_MUI)
#  define PRODUCT_VERSION_NUMBER MUI_VERSION
#elif defined(VMX86_ENTERPRISE_DESKTOP)
#  define PRODUCT_VERSION_NUMBER WORKSTATION_ENTERPRISE_VERSION
#elif defined(VMX86_DESKTOP)
#  if defined(__APPLE__)
#    define PRODUCT_VERSION_NUMBER FUSION_VERSION
#  else
#    define PRODUCT_VERSION_NUMBER WORKSTATION_VERSION
#  endif
#elif defined(VMX86_VPX)
#  if defined(XVP)
#     define PRODUCT_VERSION_NUMBER XVP_VERSION
#  else
#     define PRODUCT_VERSION_NUMBER VPX_VERSION
#  endif
#elif defined(VMX86_WBC)
#  define PRODUCT_VERSION_NUMBER WBC_VERSION
#elif defined(VMX86_SDK)
#  define PRODUCT_VERSION_NUMBER SDK_VERSION
#elif defined(VMX86_P2V)
#  define PRODUCT_VERSION_NUMBER P2V_VERSION
#elif defined(VMX86_VIPERL)
#  define PRODUCT_VERSION_NUMBER VIPERL_VERSION
#elif defined(VMX86_SYSIMAGE)
#  define PRODUCT_VERSION_NUMBER SYSIMAGE_VERSION
#elif defined(VMX86_VCB)
#  define PRODUCT_VERSION_NUMBER VCB_VERSION
#elif defined(VMX86_FOUNDRY)
#  define PRODUCT_VERSION_NUMBER FOUNDRY_VERSION
#elif defined(VMX86_VMLS)
#  define PRODUCT_VERSION_NUMBER VMLS_VERSION
#elif defined(VMX86_VLICENSE)
#  define PRODUCT_VERSION_NUMBER VLICENSE_VERSION
#elif defined(VMX86_DDK)
#  define PRODUCT_VERSION_NUMBER DDK_VERSION
#elif defined(VMX86_TOOLS)
#  define PRODUCT_VERSION_NUMBER TOOLS_VERSION
#elif defined(VMX86_VDDK)
#  define PRODUCT_VERSION_NUMBER VDDK_VERSION
#elif defined(VMX86_BOOMERANG)
#  define PRODUCT_VERSION_NUMBER BOOMERANG_VERSION
#elif defined(VMX86_HBR_SERVER)
#  define PRODUCT_VERSION_NUMBER ESX_VERSION
#elif defined(VMX86_VIEW)
#  define PRODUCT_VERSION_NUMBER VIEW_VERSION
#endif

/*
 * Continue to just append BUILD_NUMBER here, PRODUCT_BUILD_NUMBER is
 * not needed in the string.
 */

#define PRODUCT_VERSION_STRING PRODUCT_VERSION_NUMBER " " BUILD_NUMBER

/*
 * The license manager requires that PRODUCT_VERSION_STRING matches the
 * following pattern: <x>[.<y>][.<z>].
 *
 * If platforms are on different version numbers, manage it here.
 */

/*
 * Note: changing PRODUCT_NAME_FOR_LICENSE and PRODUCT_LICENSE_VERSION
 * or macros it cleverly depends on (such as PRODUCT_NAME) requires a
 * coordinated dormant license file change. Otherwise licensing for
 * that product may break because the Licensecheck API is being passed
 * a parameter that no longer match the content of the dormant license
 * file.
 */
#define PRODUCT_MAC_DESKTOP_VERSION_STRING_FOR_LICENSE "5.0"

#if defined(VMX86_TOOLS)
/* This product doesn't use a license */
#  define PRODUCT_VERSION_STRING_FOR_LICENSE ""
#  define PRODUCT_LICENSE_VERSION "0.0"
#else
#  if defined(VMX86_SERVER)
#    define PRODUCT_LICENSE_VERSION "5.0"
#  elif defined(VMX86_WGS_MIGRATION)
#    define PRODUCT_LICENSE_VERSION "1.0"
#  elif defined(VMX86_WGS)
#    define PRODUCT_LICENSE_VERSION "3.0"
#  elif defined(VMX86_ENTERPRISE_DESKTOP)
#    define PRODUCT_LICENSE_VERSION "1.0"
#  elif defined(VMX86_DESKTOP)
#    if defined(__APPLE__)
#      define PRODUCT_LICENSE_VERSION PRODUCT_MAC_DESKTOP_VERSION_STRING_FOR_LICENSE
#    else
#      define PRODUCT_LICENSE_VERSION "9.0"
#    endif
#  elif defined(VMX86_VPX)
#    define PRODUCT_LICENSE_VERSION "5.0"
#    define PRODUCT_LICENSE_FILE_VERSION "5.1.0.6"
#  elif defined(VMX86_WBC)
#    define PRODUCT_LICENSE_VERSION "1.0"
#  elif defined(VMX86_SDK)
#    define PRODUCT_LICENSE_VERSION "1.0"
#  elif defined(VMX86_P2V)
#    define PRODUCT_LICENSE_VERSION "1.0"
#  else
#    define PRODUCT_LICENSE_VERSION "0.0"
#  endif
#  define PRODUCT_VERSION_STRING_FOR_LICENSE PRODUCT_LICENSE_VERSION
#endif

#define PRODUCT_PLAYER_VERSION_STRING_FOR_LICENSE "5.0"

/*
 * This is for ACE Management Server
 * Since there is no separate product defined for Ace Mgmt Server
 * (i.e. PRODUCT=xxx when running makefile), we can not used the
 * generic PRODUCT_LICENSE_VERSION and PRODUCT_VERSION_STRING_FOR_LICENSE
 * definition.
 * As a result, the specific ACE_MGMT_SERVER_VERSION_STRING_FOR_LICENSE
 * is used instead.
 * A similar reason is used also for the PRODUCT_NAME_FOR_LICENSE definition
 * in the vm_product.h
 */

#define ACE_MGMT_SERVER_VERSION_STRING_FOR_LICENSE "2.0"

/*
 * The configuration file version string should be changed
 * whenever we make incompatible changes to the config file
 * format or to the meaning of settings.  When we do this,
 * we must also add code that detects the change and can
 * convert an old config file to a new one.
 */

#define CONFIG_VERSION_VARIABLE		"config.version"

/*
 * PREF_VERSION_VARIABLE somehow cannot be written through Dictionary_Write
 * (there is a bug after the first reload). So it's not used.
 */
/* #define PREF_VERSION_VARIABLE		"preferences.version"*/

#define CONFIG_VERSION_DEFAULT		"1"	/* if no version in file*/
#define CONFIG_VERSION                  "8"

#define CONFIG_VERSION_UNIFIEDSVGAME	"3"	/* Merged (S)VGA for WinME*/
#define CONFIG_VERSION_UNIFIEDSVGA	"4"	/* Merged (S)VGA enabled.  -J.*/
#define CONFIG_VERSION_440BX		"5"	/* 440bx becomes default */
#define CONFIG_VERSION_NEWMACSTYLE	"3"	/* ethernet?.oldMACStyle */
#define CONFIG_VERSION_WS2              "2"     /* config version of WS2.0.x */
#define CONFIG_VERSION_MIGRATION        "6"     /* migration work for WS3 */
#define CONFIG_VERSION_ESX2             "6"     /* config version of ESX 2.x */
#define CONFIG_VERSION_UNDOPOINT        "7"     /* Undopoint paradigm (WS40) */
#define CONFIG_VERSION_WS4              "7"     /* config version of WS4.0.x */
#define CONFIG_VERSION_MSNAP            "8"     /* Multiple Snapshots */
#define CONFIG_VERSION_WS5              "8"     /* WS5.0 */

/*
 * Product version strings allows UIs to refer to a single place for specific
 * versions of product names.  These do not include a "VMware" prefix.
 */

#define PRODUCT_VERSION_SCALABLE_SERVER_1 PRODUCT_SCALABLE_SERVER_BRIEF_NAME " 1.x"
#define PRODUCT_VERSION_SCALABLE_SERVER_2 PRODUCT_SCALABLE_SERVER_BRIEF_NAME " 2.x"
#define PRODUCT_VERSION_SCALABLE_SERVER_3 PRODUCT_SCALABLE_SERVER_BRIEF_NAME " 3.x"
#define PRODUCT_VERSION_SCALABLE_SERVER_30 PRODUCT_SCALABLE_SERVER_BRIEF_NAME " 3.0"
#define PRODUCT_VERSION_SCALABLE_SERVER_31 PRODUCT_SCALABLE_SERVER_BRIEF_NAME " 3.5"
#define PRODUCT_VERSION_SCALABLE_SERVER_40 PRODUCT_ESXI_BRIEF_NAME " 4.x"
#define PRODUCT_VERSION_SCALABLE_SERVER_50 PRODUCT_ESXI_BRIEF_NAME " 5.0"
#define PRODUCT_VERSION_SCALABLE_SERVER_51 PRODUCT_ESXI_BRIEF_NAME " 5.1"
#define PRODUCT_VERSION_WGS_1 "Server 1.x"
#define PRODUCT_VERSION_WGS_2 "Server 2.x"
#define PRODUCT_VERSION_GSX_3 "GSX Server 3.x"
#define PRODUCT_VERSION_WORKSTATION_4 PRODUCT_WORKSTATION_BRIEF_NAME " 4.x"
#define PRODUCT_VERSION_WORKSTATION_5 PRODUCT_WORKSTATION_BRIEF_NAME " 5.x"
#define PRODUCT_VERSION_WORKSTATION_6 PRODUCT_WORKSTATION_BRIEF_NAME " 6.0"
#define PRODUCT_VERSION_WORKSTATION_65 PRODUCT_WORKSTATION_BRIEF_NAME " 6.5"
#define PRODUCT_VERSION_WORKSTATION_7 PRODUCT_WORKSTATION_BRIEF_NAME " 7.x"
#define PRODUCT_VERSION_WORKSTATION_80 PRODUCT_WORKSTATION_BRIEF_NAME " 8.0"
#define PRODUCT_VERSION_WORKSTATION_90 PRODUCT_WORKSTATION_BRIEF_NAME " 9.0"
#define PRODUCT_VERSION_WORKSTATION_2013 PRODUCT_WORKSTATION_BRIEF_NAME " Bendezium"
#define PRODUCT_VERSION_WORKSTATION_ENTERPRISE_1 "ACE 1.x"
#define PRODUCT_VERSION_WORKSTATION_ENTERPRISE_2 "ACE 2.0"
#define PRODUCT_VERSION_WORKSTATION_ENTERPRISE_25 "ACE 2.5"
#define PRODUCT_VERSION_PLAYER_1 PRODUCT_PLAYER_BRIEF_NAME " 1.x"
#define PRODUCT_VERSION_MAC_DESKTOP_1 PRODUCT_MAC_DESKTOP_BRIEF_NAME " 1.1"
#define PRODUCT_VERSION_MAC_DESKTOP_2 PRODUCT_MAC_DESKTOP_BRIEF_NAME " 2.x"
#define PRODUCT_VERSION_MAC_DESKTOP_3 PRODUCT_MAC_DESKTOP_BRIEF_NAME " 3.x"
#define PRODUCT_VERSION_MAC_DESKTOP_40 PRODUCT_MAC_DESKTOP_BRIEF_NAME " 4.0"
#define PRODUCT_VERSION_MAC_DESKTOP_50 PRODUCT_MAC_DESKTOP_BRIEF_NAME " 5.0"
#define PRODUCT_VERSION_MAC_DESKTOP_2013 PRODUCT_MAC_DESKTOP_BRIEF_NAME " Boo Berry"
#endif