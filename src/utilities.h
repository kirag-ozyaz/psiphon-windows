/*
 * Copyright (c) 2012, Psiphon Inc.
 * All rights reserved.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#pragma once


bool ExtractExecutable(DWORD resourceID, const TCHAR* exeFilename, tstring& path);

// Possible return values:
//  ERROR_SUCCESS on success
//  WAIT_TIMEOUT if timeout exceeded
//  ERROR_SYSTEM_PROCESS_TERMINATED if process died
//  ERROR_OPERATION_ABORTED if cancel event signaled
// process and cancelEvent can be NULL
DWORD WaitForConnectability(
        int port, 
        DWORD timeout, 
        HANDLE process, 
        const vector<const bool*>& signalStopFlags);

bool WriteRegistryDwordValue(const string& name, DWORD value);

bool ReadRegistryDwordValue(const string& name, DWORD& value);

bool WriteRegistryStringValue(const string& name, const string& value);

bool ReadRegistryStringValue(const string& name, string& value);

// Text metrics are relative to default font

int TextHeight(void);

int TextWidth(const TCHAR* text);

int LongestTextWidth(const TCHAR* texts[], int count);

// Returns true if at least one item in the array is true.
bool TestBoolArray(const vector<const bool*>& boolArray);

string Hexlify(const unsigned char* input, size_t length);

string Dehexlify(const string& input);