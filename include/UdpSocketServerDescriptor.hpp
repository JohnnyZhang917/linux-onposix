/*
 * UdpSocketServerDescriptor.hpp
 *
 * Copyright (C) 2012 Evidence Srl - www.evidence.eu.com
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301 USA
 */


#ifndef UDPSOCKETSERVERDESCRIPTOR_HPP_
#define UDPSOCKETSERVERDESCRIPTOR_HPP_

#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/un.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <string>

#include "PosixDescriptor.hpp"

namespace onposix {

/**
 * \brief Socket descriptor for connection-less communications.
 *
 * This is a class to accept connection-less connections.
 *
 * Example of usage:
 * \code
 * UdpSocketServerDescriptor serv ("/tmp/mysocket");
 * Buffer b (10);
 * serv.read(b, b.getSize());
 * \endcode
 */

class UdpSocketServerDescriptor: public PosixDescriptor {

	UdpSocketServerDescriptor(const UdpSocketServerDescriptor&);
	UdpSocketServerDescriptor& operator=(const UdpSocketServerDescriptor&);

public:
	UdpSocketServerDescriptor(const uint16_t port);
	UdpSocketServerDescriptor(const std::string& name);

	/**
	 * \brief Destructor.
	 * It just calls close() to close the descriptor.
	 */
	virtual ~UdpSocketServerDescriptor(){
		close();
	}

	/**
	 * \brief Close the descriptor
	 */
	inline void close(){
		::close(fd_);
	}
};

} /* onposix */

#endif /* UDPSOCKETSERVERDESCRIPTOR_HPP_ */