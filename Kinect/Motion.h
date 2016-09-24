#pragma once
namespace OzansMotions
{
	class Motion
	{
	public:
		Motion();
		~Motion();

		void setJumpData(const OzansOrgans::Organ);
		OzansOrgans::Organ getJumpData(void) const;

		void setHandShakeData(const OzansOrgans::Organ);
		OzansOrgans::Organ getHandShakeData(void) const;

	private:
		OzansOrgans::Organ jump;
		OzansOrgans::Organ handShake;

	};
}