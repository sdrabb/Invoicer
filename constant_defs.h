#ifndef CONSTANT_DEFS_H
#define CONSTANT_DEFS_H

/* map model <--> db_table Receiver */
#define  RECEIVER_NAME_COLUMN  (0)
#define  RECEIVER_SURNAME_COLUMN  (1)
#define  RECEIVER_ADDRESS_COLUMN  (2)
#define  RECEIVER_CIVIC_NUMBER_COLUMN  (3)
#define  RECEIVER_CAP_COLUMN  (4)
#define  RECEIVER_PROVINCE_COLUMN  (5)
#define  RECEIVER_PIVA_COLUMN  (6)
#define  RECEIVER_FISCAL_CODE_COLUMN  (7)
#define  RECEIVER_MAIL_COLUMN  (8)
#define  RECEIVER_ID_COLUMN  (9)


/* map model <--> db_table Invoice */
#define INVOICE_ID_COLUMN   (0)
#define INVOICE_PROGRESSIVE_NUMBER_COLUMN   (1)
#define INVOICE_TAXABLE_COLUMN   (2)
#define INVOICE_OWNER_COLUMN   (3)
#define INVOICE_DATE_COLUMN   (4)


/* map model <--> db_table Article */
#define ARTICLE_ID_COLUMN   (0)
#define ARTICLE_NAME_COLUMN   (1)
#define ARTICLE_PRICE_COLUMN   (2)

/* map model <--> db_table Article2Invoice */
#define ARTICLE2INVOICE_ARTICLE_COLUMN   (0)
#define ARTICLE2INVOICE_INVOICE_COLUMN   (1)
#define ARTICLE2INVOICE_QUANTITY_COLUMN   (2)





#endif // CONSTANT_DEFS_H
