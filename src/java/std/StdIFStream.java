package std;

import org.xbig.base.InstancePointer;
import org.xbig.base.NativeObject;

public class StdIFStream extends NativeObject {

	protected StdIFStream(InstancePointer pInstance) {
		super(pInstance);
	}

	protected StdIFStream(InstancePointer pInstance, boolean createdByLibrary) {
		super(pInstance, createdByLibrary);
	}

	public void delete() {
		if (this.remote)
			throw new RuntimeException(
					"can't dispose object created by the library");
		_dispose(object.pointer);
	}

	/**
	 * Opens a file and attaches it to the filebuf object and thus to the
	 * stream.<br>
	 * Opens a disk file and attaches it to the streams filebuf object. If the
	 * filebuf object is already attached to an open file, or if a filebuf call
	 * fails, the ios::failbit is set. If the file is not found, then the
	 * ios::failbit is set only if the ios::nocreate mode was used.
	 * 
	 * @param szName
	 *            The name of the file to be opened during construction.
	 * @param nMode
	 *            An integer containing bits defined as ios enumerators that can
	 *            be combined with the OR ( | ) operator. See the ifstream
	 *            constructor for a list of the enumerators. The ios::in mode is
	 *            implied.
	 * @param nProt
	 *            The file protection specification; defaults to the static
	 *            integer filebuf::openprot. See the ifstream constructor for a
	 *            list of the other allowed values.
	 */
	// void open( const char* szName, int nMode = ios::in, int nProt =
	// filebuf::openprot );
	public void open(String szName, int nMode, int nProt) {
		_open(object.pointer, szName, nMode, nProt);
	}

	/**
	 * Closes the streams file.<br>
	 * Calls the close member function for the associated filebuf object. This
	 * function, in turn, closes the file and disconnects the file from the
	 * filebuf object. The filebuf object is not destroyed. The streams error
	 * state is cleared unless the call to filebuf::close fails.
	 */
	// void close();
	public void close() {
		_close(object.pointer);
	}

	/**
	 * Attaches the specified reserve area to the streams filebuf object.
	 * 
	 * @return If the file is open and a buffer has already been allocated, the
	 *         function returns NULL; otherwise it returns a pointer to the
	 *         filebuf, which is cast as a streambuf. The reserve area will not
	 *         be released by the destructor.
	 * 
	 * @param pch
	 *            A pointer to a previously allocated reserve area of length
	 *            nLength. A NULL value indicates an unbuffered stream.
	 * @param nLength
	 *            The length (in bytes) of the reserve area. A length of 0
	 *            indicates an unbuffered stream.
	 */
	// streambuf* setbuf( char* pch, int nLength );
	public StdStreambuf setbuf(char[] pch) {
		long ptr = _setbuf(object.pointer, pch, pch.length);
		if (ptr == 0)
			return null;
		InstancePointer ptrFileInputStream = new InstancePointer(ptr);
		return new StdStreambuf(ptrFileInputStream);
	}

	/**
	 * Sets the streams mode to binary or text.<br>
	 * This function sets the binary/text mode of the streams filebuf object. It
	 * may be called only after the file is opened.
	 * 
	 * @return The previous mode; 1 if the parameter is invalid, the file is not
	 *         open, or the mode cannot be changed.
	 * 
	 * @param nMode
	 *            An integer that must be one of the following static filebuf
	 *            constants:
	 *            <li><b>filebuf::text</b> Text mode (newline characters
	 *            translated to and from carriage returnlinefeed pairs).</li>
	 *            <li><b>filebuf::binary</b> Binary mode (no translation).</li>
	 */
	// int setmode( int nMode = filebuf::text );
	public int setmode(int nMode) {
		return _setmode(object.pointer, nMode);
	}

	/**
	 * Attaches this stream to the open file specified by fd.<br>
	 * The function fails when the stream is already attached to a file. In that
	 * case, the function sets ios::failbit in the streams error state.
	 * 
	 * @param fd
	 *            A file descriptor as returned by a call to the run-time
	 *            function _open or _sopen; filedesc is a typedef equivalent to
	 *            int.
	 */
	// void attach( filedesc fd );
	public void attach(int fd) {
		_attach(object.pointer, fd);
	}

	/**
	 * Gets the streams filebuf object.
	 * 
	 * @return Returns a pointer to the filebuf buffer object that is associated
	 *         with this stream. (This is not the character buffer; the filebuf
	 *         object contains a pointer to the character area.)
	 */
	// filebuf* rdbuf() const;
	public StdFileBuf rdbuf() {
		long ptr = _rdbuf(object.pointer);
		if (ptr == 0)
			return null;
		InstancePointer ptrFileInputStream = new InstancePointer(ptr);
		return new StdFileBuf(ptrFileInputStream);
	}

	/**
	 * Returns the file descriptor associated with the stream.
	 * 
	 * @return Returns the file descriptor associated with the stream; filedesc
	 *         is a typedef equivalent to int. Its value is supplied by the
	 *         underlying file system.
	 */
	// filedesc fd() const;
	public int fd() {
		return _fd(object.pointer);
	}

	/**
	 * Tests whether the streams file is open.
	 * 
	 * @return Returns a nonzero value if this stream is attached to an open
	 *         disk file identified by a file descriptor; otherwise 0. ifstream
	 *         Overview | Input Stream Classes
	 */
	// int is_open() const;
	public int is_open() {
		return _is_open(object.pointer);
	}

	private native void _dispose(long pInstance);

	private native void _open(long pInstance, String szName, int nMode,
			int nProt);

	private native void _close(long pInstance);

	private native long _setbuf(long pInstance, char[] pch, int nLength);

	private native int _setmode(long pInstance, int nMode);

	private native void _attach(long pInstance, int fd);

	private native long _rdbuf(long pInstance);

	private native int _fd(long pInstance);

	private native int _is_open(long pInstance);
}
