/*
 * Copyright (c) 2021, Oracle and/or its affiliates. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 *
 * This code is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 only, as
 * published by the Free Software Foundation.
 *
 * This code is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * version 2 for more details (a copy is included in the LICENSE file that
 * accompanied this code).
 *
 * You should have received a copy of the GNU General Public License version
 * 2 along with this work; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 * Please contact Oracle, 500 Oracle Parkway, Redwood Shores, CA 94065 USA
 * or visit www.oracle.com if you need additional information or have any
 * questions.
 */

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.nio.ByteBuffer;
import java.nio.channels.FileChannel;
import java.nio.file.Files;
import java.nio.file.Path;
import static java.nio.file.StandardOpenOption.*;

/* @test
 * @bug 8263898
 * @summary Verify a byte can be written to the null device.
 * @requires os.family == "windows"
 * @run main NulDevice
*/
public class NulDevice {
    public static void main(final String[] args) throws IOException {
        System.getProperties().list(System.out);
        System.out.println();
        Path path = Path.of("nul");
        try (final OutputStream os = Files.newOutputStream(path)) {
            os.write(0x02);
            System.out.printf("Wrote a byte to %s%n", path);
            try (InputStream is = Files.newInputStream(path);) {
                int aByte = is.read();
                System.out.printf("read %d from %s%n", aByte, path);
                if (aByte != -1) {
                    throw new RuntimeException("Should only read -1 from NUL");
                }
            }
        }
        try (final OutputStream os = Files.newOutputStream(path, WRITE)) {
            os.write(0x02);
            System.out.printf("Wrote a byte to %s%n", path);
        }
        try (final FileChannel ch = FileChannel.open(path, CREATE,
             TRUNCATE_EXISTING, WRITE)) {
            byte[] bytes = "Whatever".getBytes();
            ByteBuffer buf = ByteBuffer.allocate(2*bytes.length);
            buf.put(bytes);
            int nw = ch.write(buf);
            System.out.printf("Wrote %d bytes to %s%n", nw, path);
            if (nw != bytes.length) {
                throw new RuntimeException("Should write " + bytes.length +
                    " to NUL");
            }
        }
    }
}
