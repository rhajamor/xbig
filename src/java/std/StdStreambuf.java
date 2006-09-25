package std;

import org.xbig.base.InstancePointer;
import org.xbig.base.NativeObject;

/**
 * std::streambuf wrapper.
 * @author hrung
 */
public class StdStreambuf extends NativeObject {

	/**
	 * Internal constructor
	 */
	public StdStreambuf(InstancePointer pInstance) {
		super(pInstance);
	}

	/**
	 * Internal constructor
	 */
	public StdStreambuf(InstancePointer pInstance, boolean createdByLibrary) {
		super(pInstance, createdByLibrary);
	}

	@Override
	public void delete() {
		// TODO Auto-generated method stub
		throw new UnsupportedOperationException();
	}
}
