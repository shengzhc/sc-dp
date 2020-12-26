"""

Facade Pattern


1. Facade Pattern is "analog" to gateways which is a thin layer of interface
   interacting with the big/complex sub-systems behind.
2. Facade itself combines how to use sub-system to achieve the final result,
   but surface the result through interface back to application/client.
   Application/client can choose different facade to work with different sub-system
   if needed witthout changing application/client code.
3. Facade Pattern decouples the client/application from the sub-system, and make classes
   in the sub-system invisible to the client/application.

"""


class SubsystemVideoReader:
	def onDesc(self):
		print("SubsystemVideoReader::onDesc()")


class SubsystemBitrateReader:
	def onDesc(self):
		print("SubsystemBitrateReader::onDesc()")


class VideoConverterFacade:
	def __init__(self, vr, br):
		self.vr = vr
		self.br = br


	def convert_video(self):
		print("VideoConverterFacade::convert_video()")
		self.vr.onDesc()
		self.br.onDesc()



def client():
	facade = VideoConverterFacade(SubsystemVideoReader(), SubsystemBitrateReader())
	facade.convert_video()


if __name__ == "__main__":
	client()